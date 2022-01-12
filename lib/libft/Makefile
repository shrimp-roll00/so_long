MAKEFLAGS += s

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIB = ar -rcs

INC = libft.h

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
	ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isspace.c ft_isalpha.c ft_isdigit.c\
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c\
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strndup.c ft_split.c\
	ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c get_next_line.c get_next_line_utils.c ft_printf.c\
	ft_printf_utils.c ft_printf_find_flags.c ft_printf_handle_s.c\
	ft_printf_handle_c.c ft_printf_handle_p.c ft_printf_handle_i_d.c\
	ft_printf_handle_u.c ft_printf_handle_xs.c ft_printf_handle_n.c\
	ft_printf_handle_f.c ft_itoa_base.c ft_itoa_double.c ft_strcmp.c
OBJ = $(SRC:.c=.o)

SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ_B = $(SRC_B:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $@ $?

bonus: $(OBJ_B)
	$(LIB) $(NAME) $^

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus


