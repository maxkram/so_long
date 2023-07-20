/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:39 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 19:41:32 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_wall(char c)
{
	if (c != '1')
		return (TRUE);
	return (FALSE);
}

int	upper_wall_opened(char *upper_wall)
{
	int	i;

	i = 0;
	while (upper_wall[i] != 0)
		if (check_wall(upper_wall[i++]))
			return (TRUE);
	return (FALSE);
}

int	lower_wall_opened(char *lower_wall)
{
	int	i;

	i = 0;
	while (lower_wall[i] != 0)
		if (lower_wall[i++] != '1')
			return (TRUE);
	return (FALSE);
}

int	sidewalls_opened(char **map, size_t array_length)
{
	size_t	i;
	size_t	string_length;

	i = 0;
	string_length = ft_strlen(*map);
	while (i < array_length)
	{
		if (check_wall(map[i][0]) || check_wall(map[i][string_length - 1]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	broken_map(char **map)
{
	size_t	array_length;

	array_length = arrlength(map);
	if (broken_map_struct(map, array_length))
		return (TRUE);
	if (upper_wall_opened(*map))
		return (TRUE);
	if (sidewalls_opened(map, array_length))
		return (TRUE);
	if (lower_wall_opened(map[array_length - 1]))
		return (TRUE);
	return (FALSE);
}
