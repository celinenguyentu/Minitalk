# -------------------------------- VARIABLES --------------------------------- #

NAME			=	libft.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3
AR				=	ar rc
RM				=	rm -rf

HFILES_DIR		=	./includes/

MAIN_DIR		=	./srcs/
MAIN_FILES		= 	ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_strlen.c \
					ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strnstr.c \
					ft_atoi.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c 

PRINTF_DIR		=	./srcs/ft_printf/
PRINTF_FILES	=	ft_atoi_digits.c \
					ft_strdlen.c \
					ft_putchar.c \
					ft_putnchar.c \
					ft_putnstr.c \
					ft_putuint.c \
					ft_uintlen.c \
					ft_printf.c \
					ft_vprintf.c \
					print_arg.c \
					print_char.c \
					print_str.c \
					print_ptr.c \
					print_int.c \
					print_uint.c \
					print_percent.c \
					print_unknown.c \
					print_intprefix.c \
					init_formatspecs.c \
					reset_formatspecs.c \
					clean_formatspecs.c \
					update_formatspecs.c \
					precision_overflow_handler.c \
					check.c 

MAIN_SRCS		=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))
PRINTF_SRCS		=	$(addprefix $(PRINTF_DIR), $(PRINTF_FILES))

MAIN_OJBS		=	$(MAIN_SRCS:.c=.o)
PRINTF_OBJS		=	$(PRINTF_SRCS:.c=.o)

# ---------------------------------- RULES ----------------------------------- #

.c.o: 
				@${CC} ${CFLAGS} -c -I $(HFILES_DIR) $< -o $@

all: 			$(NAME)

$(NAME):		$(MAIN_OJBS) $(PRINTF_OBJS)
				@$(AR) $(NAME) $(MAIN_OJBS) $(PRINTF_OBJS)
				@echo "Created libft.a."

clean:
				@$(RM) $(OJBS) $(MAIN_OJBS) $(PRINTF_OBJS)

fclean:			clean
				@$(RM) $(NAME)
				@echo "Removed libft.a."

re:				fclean all

.PHONY:			all clean fclean re
