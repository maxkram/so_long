/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:09 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 15:09:53 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count(char *map, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
		if (map[i] == c)
			count++;
	return (count);
}

int	broken_parts(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E' || c == '\n')
		return (TRUE);
	return (FALSE);
}

int	broken_components(char *map)
{
	int	hero;
	int	exit;
	int	collect;
	int	i;

	hero = count(map, 'P');
	exit = count(map, 'E');
	collect = count(map, 'C');
	i = -1;
	while (map[++i])
		if (broken_parts(map[i]) == FALSE)
			return (TRUE);
	if (hero == 1 && exit == 1 && collect > 0)
		return (FALSE);
	return (TRUE);
}

int	broken_map_struct(char **map, size_t array_length)
{
	size_t	ligne;
	size_t	i;

	if (!*map)
		return (1);
	ligne = ft_strlen(*map);
	i = 1;
	while (i < array_length)
		if (ft_strlen(map[i++]) != ligne)
			return (TRUE);
	return (FALSE);
}
