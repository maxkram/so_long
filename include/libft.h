/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:05:23 by ssergiu           #+#    #+#             */
/*   Updated: 2023/07/19 19:26:29 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

typedef struct s_visited
{
	void				*position;	
	int					x;
	int					y;
	struct s_visited	*next;
}	t_list;

// typedef struct s_visited	t_list;

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				**ft_split(char const *s, char c);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void*));
char				*ft_itoa(int n);
int					ft_lstsize(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void*));

size_t				ft_strlen_protected(const char *s);
char				*ft_substr_sizeprotected(char const *s,
						unsigned int start, size_t len);
char				*ft_strjoin_sizeprotected(char const *s1, char const *s2);
char				*get_until(char **buffer, int until);
char				*read_line(int fd, char **buffer);
char				*get_next_line(int fd);
char				*read_find(int fd, char **buffer,
						char *buf_read, size_t *by_read);

void				ft_putchar_i(char c, int *i);
void				ft_puthex(unsigned long long n, int *i, char *base);
void				ft_putint(unsigned int nb, int *i);
void				ft_putstr_i(char *str, int *i);
void				ft_putnbr_i(int nb, int *i);
void				ft_print_all(const char *str, int *i, va_list args, int x);
int					ft_printf(char const *str, ...);
char				*ft_strchr(const char *str, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);
#endif
