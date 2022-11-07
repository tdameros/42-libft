.PHONY: all clean fclean re bonus
.SILENT:

#**************************************  VARIABLES  **************************************#

NAME			=	libft.a
LOGS			=	true

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

LIST_BONUS		=	ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \

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

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar -rcs

# --------------  DEBUGS -------------- #

DB				=	gdb
DBFLAGS			=	-g3 -fsanitize=address

# -------------  COMMANDS ------------- #

RM				=	rm -rf
MKDIR			=	mkdir -p

# --------------- COLORS -------------- #

RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m

#**************************************  RULES  **************************************#

all : $(NAME)

# ---------- VARIABLES RULES ---------- #

$(NAME):  $(DIR_OBJS) $(OBJS) $(HEADERS) Makefile
			$(AR) $(NAME) $(OBJS);
			@if [ $(LOGS) = "true" ]; then\
				printf "${BLUE}Generation with success of $(NAME) ☑️\n";\
			fi

bonus:	$(DIR_OBJS) $(OBJS) $(OBJS_BONUS) $(HEADERS) Makefile
			$(AR) $(NAME) $(OBJS) $(OBJS_BONUS);
			@if [ $(LOGS) = "true" ]; then\
				printf "${BLUE}Generation with success of $(NAME) bonus ☑️\n";\
			fi

# ---------- COMPILED RULES ----------- #

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c $(HEADERS)
				$(CC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@if [ $(LOGS) = "true" ]; then\
        			printf "${GREEN}Successful compilation of $< ✅\n";\
    			fi

$(DIR_OBJS):
				$(MKDIR) $(DIR_OBJS)

clean:
		$(RM) $(DIR_OBJS)
		@if [ $(LOGS) = "true" ]; then\
        	printf "${RED}Successful cleaning objects files 🗑️\n";\
    	fi

fclean: clean
		$(RM) $(NAME)
		@if [ $(LOGS) = "true" ]; then\
        	printf "${RED}Successful cleaning $(NAME) 🗑️\n";\
    	fi

re: fclean $(NAME)
