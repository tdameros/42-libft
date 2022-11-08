.PHONY: all clean fclean re bonus

#*******************************  VARIABLES  **********************************#

NAME			=	libft.a

# --------------- FILES --------------- #

LIST_HEADERS	=	libft.h
LIST_SRCS		=	ft_isalpha.c \
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

LIST_BONUS		=	ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c \

# ------------ DIRECTORIES ------------ #

DIR_OBJS		=	./.objs/
DIR_SRCS 		= 	./
DIR_BONUS		=	./
DIR_HEADERS		=	./

# ------------- SHORTCUTS ------------- #

HEADERS			= 	$(addprefix $(DIR_HEADERS),$(LIST_HEADERS))
SRCS			=	$(addprefix $(DIR_SRCS),$(LIST_SRCS))
OBJS			=	$(addprefix $(DIR_OBJS),$(LIST_SRCS:.c=.o))
OBJS_BONUS		= 	$(addprefix $(DIR_OBJS),$(LIST_BONUS:.c=.o))

# ------------ COMPILATION ------------ #

CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar rcs

# -------------  COMMANDS ------------- #

RM				=	rm -rf
MKDIR			=	mkdir -p

#***********************************  RULES  **********************************#

all:			$(NAME)

# ---------- VARIABLES RULES ---------- #

$(NAME):		$(DIR_OBJS) $(OBJS) $(HEADERS) Makefile
					$(AR) $(NAME) $(OBJS);

bonus:			$(DIR_OBJS) $(OBJS) $(OBJS_BONUS) $(HEADERS) Makefile
					$(AR) $(NAME) $(OBJS) $(OBJS_BONUS);

# ---------- COMPILED RULES ----------- #

$(DIR_OBJS)%.o:	$(DIR_SRCS)%.c $(HEADERS) Makefile
					$(CC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
					$(MKDIR) $(DIR_OBJS)

clean:
					$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
					$(RM) $(NAME)

re:				fclean $(NAME)
