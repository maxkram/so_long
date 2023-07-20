/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collects.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:04 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/19 15:50:32 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_and_remove_image(t_data **data, mlx_image_t *image, t_list *head)
{
	t_list	*temp;

	temp = head->next;
	mlx_delete_image((*data)->mlx, image);
	free(temp);
}

void	remove_collect(t_data **data)
{
	t_list	*head;
	int		pos_y;
	int		pos_x;

	pos_x = (*data)->player_box->instances[0].x / SIZE;
	pos_y = (*data)->player_box->instances[0].y / SIZE;
	head = (*data)->collectible_list;
	if (head->x == pos_x && head->y == pos_y)
	{
		(*data)->collectible_list = (*data)->collectible_list->next;
		mlx_delete_image((*data)->mlx, head->position);
		free(head);
		return ;
	}
	while (head->next)
	{
		if (head->next->x == pos_x && head->next->y == pos_y)
		{
			free_and_remove_image(data, head->next->position, head);
			head->next = head->next->next;
			return ;
		}
		head = head->next;
	}
}

void	player_is_on_colectible(t_data **data)
{
	mlx_instance_t	*player;
	int				pos_x;
	int				pos_y;

	player = (*data)->player_box->instances;
	pos_x = player[0].x / SIZE;
	pos_y = player[0].y / SIZE;
	if ((*data)->map[pos_y][pos_x] == 'C')
	{
		(*data)->map[pos_y][pos_x] = '0';
		remove_collect(data);
	}
}

void	all_collected(t_data *data)
{
	mlx_image_t		*exit_closed;
	mlx_image_t		*exit_opened;

	if (!data->collectible_list)
	{
		exit_closed = data->tiles->exit_img[0];
		exit_opened = data->tiles->exit_img[1];
		ft_memcpy(exit_closed->pixels, exit_opened->pixels,
			SIZE * SIZE * 4);
	}
}
