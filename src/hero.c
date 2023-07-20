/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:30 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 18:25:58 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	hero_is_on_exit(t_data **data)
{
	mlx_instance_t	*player;
	mlx_instance_t	*exit;

	player = &(*data)->player_box->instances[0];
	exit = &(*data)->tiles->exit_img[0]->instances[0];
	if (player->x == exit->x && player->y == exit->y)
		return (1);
	return (0);
}

int	check_valid_move(t_data *data, t_position *position)
{
	mlx_instance_t	*player;
	int				posx;
	int				posy;

	posx = position->x;
	posy = position->y;
	player = data->player_box->instances;
	posx = posx + player->x / SIZE;
	posy = posy + player->y / SIZE;
	if (data->map[posy][posx] != '1')
		return (1);
	return (0);
}

void	init_moves(t_data **data)
{
	(*data)->enemy_movement[0] = (t_position *)malloc(sizeof(t_position));
	(*data)->enemy_movement[1] = (t_position *)malloc(sizeof(t_position));
	(*data)->enemy_movement[2] = (t_position *)malloc(sizeof(t_position));
	(*data)->enemy_movement[3] = (t_position *)malloc(sizeof(t_position));
	(*data)->enemy_movement[4] = NULL;
	(*data)->enemy_movement[0]->x = 0;
	(*data)->enemy_movement[0]->y = -1;
	(*data)->enemy_movement[1]->x = 0;
	(*data)->enemy_movement[1]->y = 1;
	(*data)->enemy_movement[2]->x = 1;
	(*data)->enemy_movement[2]->y = 0;
	(*data)->enemy_movement[3]->x = -1;
	(*data)->enemy_movement[3]->y = 0;
}
