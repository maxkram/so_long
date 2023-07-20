NAME = libft.a

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_strlen \
		ft_strlcpy \
		ft_strncmp \
		ft_calloc \
		ft_bzero \
		ft_memcpy \
		ft_memset \
		ft_split \
		ft_putstr_fd \
		ft_putnbr_fd \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstadd_back \
		ft_lstclear \
		ft_lstsize \
		ft_lstdelone \
		ft_itoa \
		ft_printf_utils \
		ft_printf \
		get_next_line_bonus \
		get_next_line_utils \
		ft_strchr \
		ft_substr \
		ft_strdup \

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $^

%.o:%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
