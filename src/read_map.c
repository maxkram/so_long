/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:33 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/18 19:41:31 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_and_return(void *memory)
{
	free(memory);
	return (TRUE);
}

int	get_map_size(char *map)
{
	int		file;
	char	*buffer;
	int		read_size;
	int		total_size;

	file = open(map, O_RDONLY);
	buffer = malloc(100);
	read_size = read(file, buffer, 100);
	if (read_size == 0)
		return (free_and_return(buffer));
	total_size = 0;
	total_size += read_size;
	while (read_size != 0)
	{
		read_size = read(file, buffer, 100);
		total_size += read_size;
	}
	close(file);
	free(buffer);
	return (total_size);
}

char	*read_map(char *map)
{
	int		file;
	int		bytes;
	char	*map_b;

	bytes = get_map_size(map) + 1;
	map_b = ft_calloc(sizeof(char), bytes);
	file = open(map, O_RDONLY);
	read(file, map_b, bytes);
	close(file);
	return (map_b);
}
