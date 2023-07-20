/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:26 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/18 18:36:02 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	break_and_free(t_data **data)
{
	free_spring((*data)->map);
	free((*data)->map_string);
	break_idle_struct(data);
	break_tile_struct(data);
}

void	list_clear(t_list **lst)
{
	t_list	*curr;

	curr = *lst;
	while (curr)
	{
		curr = curr->next;
		free(*lst);
		*lst = curr;
	}
	*lst = NULL;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (check_args());
	else
	{
		if (map_with_errors(argv[1]))
			ft_printf("Map has errors, exiting..\n");
		else
			loop(argv[1]);
	}
	return (FALSE);
}
