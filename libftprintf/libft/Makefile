NAME		:= libft.a
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -c
SRCS		:= ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_strchr.c\
				ft_strlen.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_strrchr.c\
				ft_strncmp.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_strnstr.c\
				ft_atoi.c\
				ft_memset.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_calloc.c\
				ft_memccpy.c\
				ft_strdup.c\
				ft_strlcat.c\
				ft_strlcpy.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c

BONUS_SRCS	:= 	ft_lstnew_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstmap_bonus.c

BONUS_OBJS	:= $(BONUS_SRCS:.c=.o)
OBJS		:= $(SRCS:.c=.o)
RM			:= rm -rf
HEADER		:= libft.h
.PHONY: all clean fclean re bonus

%.o: %.c $(HEADER) $(SRCS) $(BONUS_SRCS)
	$(CC) $(CFLAGS) $< -o $@ -include $(HEADER)

$(NAME): $(OBJS) $(HEADER) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME) bonus

bonus: $(BONUS_OBJS) $(OBJS) $(HEADER)
	ar rcs libft.a $(OBJS) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

