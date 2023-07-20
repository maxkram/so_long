/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:47 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 20:53:05 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include "libft.h"
# include <sys/errno.h>
# include <stdio.h>
# include <string.h>
# define SPRITE 64
# define SIZE 32

# define FILE_MSG "Error\nIncorrect number of parameters, only 2 are accepted.\n"
# define EMPTY_MSG "Error\nMap is empty\n"
# define MIN_TILES_MSG "Error\nYou don't have the correct components\n"
# define STRUCT_MSG "Error\nMap or structure is not correct\n"
# define PATH_MSG "Error\nThere is not a valid path\n"

enum e_bool
{
	FALSE,
	TRUE
};

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*enemy[3];
	mlx_texture_t	*exit[3];
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*exit_img[3];

}	t_texture;

typedef struct s_idle_texture
{
	mlx_texture_t	*left[9];	
	mlx_texture_t	*right[9];	
	mlx_image_t		*right_idle[9];	
	mlx_image_t		*left_idle[9];	
	mlx_image_t		*idle;
}	t_idle;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	char			*collectible_count;
	mlx_texture_t	*player;
	mlx_image_t		*score;
	t_idle			*idle;
	t_texture		*tiles;
	t_list			*collectible_list;
	t_list			*enemy_list;
	mlx_texture_t	*game_icon;
	mlx_image_t		*player_img;
	mlx_image_t		*player_box;
	t_position		*enemy_movement[5];
	char			*map_string;
	char			**map;
	int				width;
	int				height;
}	t_data;

typedef struct s_map
{
	char				**map;
	struct s_position	*player;
	struct s_position	*exit;
	struct s_visited	*visited_list;
	struct s_visited	*double_visited;
	struct s_position	*movements[5];
	char				player_moved;
	int					map_loop;
}	t_map;

int			same_coords(t_position *player, t_position *exit);
void		check_map_path(t_map *map);
void		draw_map(t_data **data);
void		free_spring(char **spring);
void		break_struct(t_map *map);
void		loop(char *argv);
void		init_tile_textures(t_data **data);
void		init_idle_texture(t_data **data);
void		break_idle_struct(t_data **data);
void		break_tile_struct(t_data **data);
void		delete_tile_textures(t_data **data);
void		delete_idle_textures(t_data **data);
t_position	*get_component(char **map, char type);
void		put_collectable(t_data **data, int width, int height);
void		remove_collect(t_data **data);
void		put_floor(t_data **data, char c, int width, int height);
void		put_door(t_data **data);
void		add_hero(t_data **data);
int			check_valid_move(t_data *data, t_position *position);
void		all_collected(t_data *data);
void		init_moves(t_data **data);
void		player_is_on_colectible(t_data **data);
int			hero_is_on_exit(t_data **data);
char		*read_map(char *map);
int			map_with_errors(char *argv);
int			broken_map_name(char *filename);
int			broken_map(char **map);
int			broken_map_struct(char **map, size_t array_length);
int			not_wall(char c);
int			broken_components(char *map);
int			check_args(void);
int			components_error(char *map_string);
int			structure_error(t_map *map);
int			empty_map(char *map_string);
int			no_valid_path(t_map *map);
int			is_valid_coord(t_position position, t_map **map);
size_t		arrlength(char **string);
t_position	*get_hero_position(char **map);
t_position	calculate_coords(t_position *player, t_position *movement);
t_map		*init_structure(char *map_string);
void		list_clear(t_list **lst);
void		init_data(t_data **data, char *argv);
void		break_and_free(t_data **data);
#endif
