NAME        	=   cub3D
LIBFT			=	./libft/libft.a
CC				=	gcc
LEAKS			=	-fsanitize=address
CFLAGS			=	-Wall -Werror -Wextra -g
RM				=	rm -f


#Directory
OBJ_DIR			=	obj/
SRC_DIR			= 	src/

SRC_MAIN		= 	main/
SRC_MAP			= 	map/
SRC_CHECKS 		=	checks/
SRC_GET_NEXT_LINE = get_next_line/
SRC_CORE		= core/

#Files
MAIN			= 	main
MAP				= 	map_init map_fix map_read map_real
CHECKS			=	map_check example_check
GET_NEXT_LINE	= 	get_next_line
CORE_MAP		= 	core_map
#FileCreate

SRC_FILES		+=	$(addprefix $(SRC_MAIN),$(MAIN))
SRC_FILES		+=	$(addprefix $(SRC_MAP),$(MAP))
SRC_FILES		+=	$(addprefix $(SRC_CHECKS),$(CHECKS))
SRC_FILES		+=	$(addprefix $(SRC_GET_NEXT_LINE),$(GET_NEXT_LINE))
SRC_FILES		+=	$(addprefix $(SRC_CORE),$(CORE_MAP))


SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF			=	.cache_exists

all:		welcome $(NAME)

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(SRC_MAIN)
			@mkdir -p $(OBJ_DIR)$(SRC_MAP)
			@mkdir -p $(OBJ_DIR)$(SRC_CHECKS)
			@mkdir -p $(OBJ_DIR)$(SRC_GET_NEXT_LINE)
			@mkdir -p $(OBJ_DIR)$(SRC_CORE)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_DIR) $@ 

norm:
			@norminette $(SRC) | grep -v Norme -B1 || true
			@echo Norminatte exception


$(NAME):	$(OBJ)
			@$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LIBFT) 
			@echo $(NAME) compiled!

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -f $(OBJF)const
			@echo Objects files cleaned!

fclean:		clean
			@$(RM) -f $(NAME)
			@echo $(NAME) executable files cleaned!

re:			fclean all
			@echo Cleaned and rebuilt

welcome:
			@echo "CUB3D"
			@echo "\n"

.PHONY:		all clean fclean re bonus norm