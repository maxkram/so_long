/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:29 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 17:16:42 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mark_map(t_map **map)
{
	(*map)->map[(*map)->player->x][(*map)->player->y] = 'X';
	(*map)->player_moved = 1;
}

void	copy_coordinates(t_position **destination, t_position **source)
{
	(*destination)->x = (*source)->x;
	(*destination)->y = (*source)->y;
}

void	player_go_to_new_position(t_position *new_pos, t_map **map)
{
	t_position	*node;

	node = (t_position *)malloc(sizeof(t_position));
	copy_coordinates(&node, &(*map)->player);
	ft_lstadd_front(&(*map)->visited_list, ft_lstnew(node));
	copy_coordinates(&(*map)->player, &new_pos);
	mark_map(map);
}

void	go_back(t_map **map)
{
	t_list		*temp;

	ft_lstadd_front(&(*map)->double_visited, ft_lstnew((*map)->player));
	if (!(*map)->visited_list)
	{
		(*map)->map_loop = 1;
		return ;
	}
	temp = (*map)->visited_list;
	(*map)->player = (*map)->visited_list->position;
	(*map)->visited_list = (*map)->visited_list->next;
	temp->next = NULL;
	free(temp);
}

void	check_map_path(t_map *map)
{
	int			i;
	t_position	new_pos;

	i = 0;
	mark_map(&map);
	while (map->map_loop == 0)
	{
		while (map->movements[i])
		{
			map->player_moved = 0;
			new_pos = calculate_coords(map->player, map->movements[i++]);
			if (is_valid_coord(new_pos, &map))
			{
				player_go_to_new_position(&new_pos, &map);
				break ;
			}
		}
		if (!map->player_moved)
			go_back(&map);
		i = 0;
	}
}
