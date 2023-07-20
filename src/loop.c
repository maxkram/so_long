/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:25 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 18:20:30 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_data(t_data **data, char *argv)
{
	int	width;
	int	height;

	(*data)->map_string = read_map(argv);
	(*data)->map = ft_split((*data)->map_string, '\n');
	width = SIZE * ft_strlen(*(*data)->map);
	height = SIZE * arrlength((*data)->map);
	(*data)->mlx = mlx_init(width, height, "so_long", true);
	(*data)->img = mlx_new_image((*data)->mlx, width, height);
	(*data)->collectible_list = NULL;
	(*data)->enemy_list = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	init_moves(data);
}

void	ft_move(t_data *data, t_position *position)
{
	mlx_image_t		*player;
	mlx_image_t		*player_box;
	static int		move;

	player = data->idle->right_idle[0];
	player_box = data->player_box;
	if (check_valid_move(data, position))
	{
		player_box->instances[0].y += position->y * SIZE;
		player_box->instances[0].x += position->x * SIZE;
		player->instances[0].y += position->y * SIZE;
		player->instances[0].x += position->x * SIZE;
		move++;
		ft_printf("Player moves: ");
		ft_printf("%d", move);
		ft_printf("\n");
	}
}

void	hook(void *param)
{
	t_data	*data;

	data = param;
	player_is_on_colectible(&data);
	all_collected(data);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data			*data;
	t_list			*head;

	data = param;
	head = data->collectible_list;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_move(data, data->enemy_movement[1]);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_move(data, data->enemy_movement[3]);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_move(data, data->enemy_movement[0]);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_move(data, data->enemy_movement[2]);
	if (hero_is_on_exit(&data) && !data->collectible_list)
	{
		ft_printf("\n>>>  Game over <<<\n");
		write(1, "\n", 1);
		mlx_close_window(data->mlx);
	}
}

void	loop(char *argv)
{
	t_data	*data;

	init_data(&data, argv);
	draw_map(&data);
	mlx_key_hook(data->mlx, keyhook, data);
	mlx_loop_hook(data->mlx, hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	if (data->collectible_list)
		list_clear(&data->collectible_list);
	break_and_free(&data);
}
