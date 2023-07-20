/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:19 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 19:14:47 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	add_hero_box(t_data **data)
{
	int			pos_x;
	int			pos_y;
	t_position	*player_pos;

	player_pos = get_component((*data)->map, 'P');
	pos_x = player_pos->x * SIZE;
	pos_y = player_pos->y * SIZE;
	(*data)->player_box = mlx_new_image((*data)->mlx, SIZE, SIZE);
	ft_memset((*data)->player_box->pixels, 0, SIZE * SIZE * 4);
	mlx_image_to_window((*data)->mlx, (*data)->player_box, pos_x, pos_y);
	free(player_pos);
}

void	draw_collects(t_data **data)
{
	int	y;
	int	x;

	y = -1;
	while ((*data)->map[++y])
	{
		x = -1;
		while ((*data)->map[y][++x])
			put_collectable(data, x, y);
	}
}

void	draw_tiles(t_data **data)
{
	int	y;
	int	x;

	y = -1;
	while ((*data)->map[++y])
	{
		x = -1;
		while ((*data)->map[y][++x])
			put_floor(data, (*data)->map[y][x], x * SIZE, y * SIZE);
	}
}

size_t	arrlength(char **string)
{
	size_t	i;	

	i = 0;
	while (string[i])
		i++;
	return (i);
}

void	draw_map(t_data **data)
{
	int	width;
	int	height;

	width = SIZE * ft_strlen(*(*data)->map);
	height = SIZE * arrlength((*data)->map);
	init_idle_texture(data);
	init_tile_textures(data);
	ft_memset((*data)->img->pixels, 255, width * height * 4);
	mlx_image_to_window((*data)->mlx, (*data)->img, 0, 0);
	draw_tiles(data);
	draw_collects(data);
	put_door(data);
	add_hero_box(data);
	add_hero(data);
}
