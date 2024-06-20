# -------------------------------- VARIABLES --------------------------------- #

SERVER_NAME		=	server
CLIENT_NAME		=	client

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3
RM				=	rm
RM_FLAGS		=	-rf

HFILES_DIR		=	./includes/

CLIENT_SRC		=	./srcs/minitalk_utils.c ./srcs/client.c
SERVER_SRC		=	./srcs/minitalk_utils.c ./srcs/server.c
CLIENT_SRC_B	=	./srcs/minitalk_utils.c ./srcs/client_bonus.c
SERVER_SRC_B	=	./srcs/minitalk_utils.c ./srcs/server_bonus.c

CLIENT_OBJS		=	$(CLIENT_SRC:.c=.o)
SERVER_OBJS		=	$(SERVER_SRC:.c=.o)
CLIENT_OBJS_B	=	$(CLIENT_SRC_B:.c=.o)
SERVER_OBJS_B	=	$(SERVER_SRC_B:.c=.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

# ---------------------------------- RULES ----------------------------------- #

.c.o: 
				@$(CC) $(CFLAGS) -c -I $(HFILES_DIR) $< -o $@

all:			mandatory

$(LIBFT):
				@make -C  >/dev/null $(LIBFT_PATH) all
				@echo "Created libft.a."

mandatory:		$(SERVER_OBJS) $(CLIENT_OBJS) $(LIBFT)
				@$(CC) $(CFLAGS) $(SERVER_OBJS) -I $(HFILES_DIR) $(LIBFT) -o $(SERVER_NAME)
				@$(CC) $(CFLAGS) $(CLIENT_OBJS) -I $(HFILES_DIR) $(LIBFT) -o $(CLIENT_NAME)
				@echo "Created binaries server and client (mandatory part)."

bonus:			$(SERVER_OBJS_B) $(CLIENT_OBJS_B) $(LIBFT)
				@$(CC) $(CFLAGS) $(SERVER_OBJS_B) -I $(HFILES_DIR) $(LIBFT) -o $(SERVER_NAME)
				@$(CC) $(CFLAGS) $(CLIENT_OBJS_B) -I $(HFILES_DIR) $(LIBFT) -o $(CLIENT_NAME)
				@echo "Created binaries server and client (bonus part)."

clean:
			@make -C >/dev/null $(LIBFT_PATH) clean
			@$(RM) $(RM_FLAGS) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_B) $(CLIENT_OBJS_B)

fclean:		clean
			@make -C >/dev/null $(LIBFT_PATH) fclean
			@echo "Removed libft.a"
			@$(RM) $(RM_FLAGS) $(SERVER_NAME) $(CLIENT_NAME)
			@echo "Removed binaries server and client."

re:			fclean all

.PHONY:		all bonus clean fclean libft mandatory re
