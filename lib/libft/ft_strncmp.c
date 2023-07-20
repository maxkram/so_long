/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:24:24 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/18 19:24:26 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	while ((s1[i] || s2[i]) && (i++ < n))
	{
		if ((unsigned char)s1[i - 1] < (unsigned char)s2[i - 1])
			return (1);
		else if ((unsigned char)s1[i - 1] > (unsigned char)s2[i - 1])
			return (1);
	}
	return (0);
}
