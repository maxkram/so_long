/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:17 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 19:36:14 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	same_coords(t_position *player, t_position *exit)
{
	if (player->x == exit->x && player->y == exit->y)
		return (TRUE);
	return (FALSE);
}

int	not_visited(t_position *position, t_list *head)
{
	t_list	*cursor;

	cursor = head;
	while (cursor)
	{
		if (same_coords(cursor->position, position))
			return (TRUE);
		cursor = cursor->next;
	}
	return (FALSE);
}

int	is_valid_coord(t_position position, t_map **map)
{
	if (!(not_visited(&position, (*map)->double_visited)
			|| not_visited(&position, (*map)->visited_list)))
		if (check_wall((*map)->map[position.x][position.y])
		&& (*map)->map[position.x][position.y])
			return (TRUE);
	return (FALSE);
}

t_position	calculate_coords(t_position *player, t_position *movement)
{
	t_position	position;

	position.x = player->x + movement->x;
	position.y = player->y + movement->y;
	return (position);
}
