SERVER			:= server
CLIENT			:= client
CFLAGS			:= -Wall -Wextra -Werror
SRCS			:= server.c client.c
OBJS			:= server.o client.o
RM				:= rm -rf
LIBFT_PATH		:= libftprintf/

all: $(SERVER) $(CLIENT)

%.o: %.c
	gcc $(CFLAGS) -c $?

$(SERVER): server.o minitalk.h libftprintf
	make all -C $(LIBFT_PATH)
	gcc -o $@ $< $(LIBFT_PATH)libftprintf.a

$(CLIENT): client.o minitalk.h libftprintf
	gcc -o $@ $< $(LIBFT_PATH)libftprintf.a

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
