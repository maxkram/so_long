/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:23 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 16:43:17 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_handling(char errnum)
{
	if (!errnum)
		ft_printf("Wrong map name");
	else
		ft_putstr_fd(strerror(errnum), 2);
	ft_printf("\n");
	return (TRUE);
}

int	broken_map_name(char *filename)
{
	int	len;
	int	file;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (error_handling(errno));
	close(file);
	len = ft_strlen(filename);
	if (ft_strncmp(filename + (len - 4), ".ber\0", 5))
		return (error_handling(0));
	return (FALSE);
}

void	free_spring(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != 0)
		free(split[i]);
	free(split);
}
