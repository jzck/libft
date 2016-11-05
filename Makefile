NAME	=	libft.a
CC		=	gcc
AR		=	ar -rc

D_SRC	=	src
D_OBJ	=	obj

O_FLAGS	=
W_FLAGS	=	-Wall -Wextra -Werror
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

D_INC	=	includes

F_SRC	:=	$(shell find $(D_SRC) -type f -regex ".*\.c$$")
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(notdir $(F_SRC:.c=.o)))

.PHONY: all clean fclean re
.NOTPARALLEL:

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/*/%.c
	@$(MKDIR) $(D_OBJ)
	@$(CC) -I$(D_INC) $(W_FLAGS) -c $< -o $@ $(DEBUG)
	@echo "(libft) Compiling "$<"..."

$(NAME): $(F_OBJ)
	@$(AR) $(NAME) $(F_OBJ)
	@echo "(libft) Linking "$@"..."
	@ranlib $(NAME)

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
