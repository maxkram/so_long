/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:37 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/20 14:46:39 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_idle_images(t_data **data)
{
	t_idle	*idle;

	idle = (*data)->idle;
	idle->right_idle[0] = mlx_texture_to_image((*data)->mlx, idle->right[0]);
	idle->right_idle[1] = mlx_texture_to_image((*data)->mlx, idle->right[1]);
	idle->right_idle[2] = mlx_texture_to_image((*data)->mlx, idle->right[2]);
	idle->right_idle[3] = mlx_texture_to_image((*data)->mlx, idle->right[3]);
	idle->right_idle[4] = mlx_texture_to_image((*data)->mlx, idle->right[4]);
	idle->right_idle[5] = mlx_texture_to_image((*data)->mlx, idle->right[5]);
	idle->right_idle[6] = mlx_texture_to_image((*data)->mlx, idle->right[6]);
	idle->right_idle[7] = mlx_texture_to_image((*data)->mlx, idle->right[7]);
	idle->right_idle[8] = NULL;
	idle->idle = mlx_texture_to_image((*data)->mlx, idle->right[0]);
}

void	load_tile_images(t_data **data)
{
	t_texture	*tiles;
	mlx_t		*mlx;

	mlx = (*data)->mlx;
	tiles = (*data)->tiles;
	tiles->floor_img = mlx_texture_to_image(mlx, tiles->floor);
	tiles->wall_img = mlx_texture_to_image(mlx, tiles->wall);
	tiles->exit_img[0] = mlx_texture_to_image(mlx, tiles->exit[0]);
	tiles->exit_img[1] = mlx_texture_to_image(mlx, tiles->exit[1]);
}

void	init_tile_textures(t_data **data)
{
	t_texture	*tiles;

	(*data)->tiles = (t_texture *)malloc(sizeof(t_texture));
	tiles = (*data)->tiles;
	tiles->floor = mlx_load_png("assets/tiles/floor/floor.png");
	tiles->wall = mlx_load_png("assets/tiles/wall/wall.png");
	tiles->exit[0] = mlx_load_png("assets/tiles/other/32.png");
	tiles->exit[1] = mlx_load_png("assets/tiles/other/34.png");
	tiles->exit[2] = NULL;
	load_tile_images(data);
	delete_tile_textures(data);
}

void	init_idle_texture(t_data **data)
{
	t_idle	*idle;

	(*data)->idle = (t_idle *)malloc(sizeof(t_idle));
	idle = (*data)->idle;
	idle->right[0] = mlx_load_png("assets/player/1.png");
	idle->right[1] = mlx_load_png("assets/player/1.png");
	idle->right[2] = mlx_load_png("assets/player/1.png");
	idle->right[3] = mlx_load_png("assets/player/1.png");
	idle->right[4] = mlx_load_png("assets/player/1.png");
	idle->right[5] = mlx_load_png("assets/player/1.png");
	idle->right[6] = mlx_load_png("assets/player/1.png");
	idle->right[7] = mlx_load_png("assets/player/1.png");
	idle->right[8] = NULL;
	load_idle_images(data);
	delete_idle_textures(data);
}
