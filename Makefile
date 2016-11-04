NAME	=	libft.a
CC		=	gcc
AR		=	ar -rc

D_SRC	=	.
D_OBJ	=	obj

O_FLAGS	=
W_FLAGS	=	-Wall -Wextra -Werror
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

F_SRC	:=	$(shell ls -1 $(D_SRC) | grep "\.c$$")
F_OBJ	:=	$(F_SRC:.c=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

.PHONY: all clean fclean re
.NOTPARALLEL:

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/%.c
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(W_FLAGS) -c $< -o $@ $(DEBUG)
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
