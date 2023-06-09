# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 20:53:18 by abelhadj          #+#    #+#              #
#    Updated: 2023/06/18 16:52:00 by abelhadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
NAME_B	= cub3D_Bonus

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit


LIBFT = $(addprefix  libft/, ft_isdigit ft_memset  ft_isprint ft_putendl_fd ft_itoa ft_strmapi \
		ft_bzero ft_putchar_fd  ft_atoi ft_strncmp var_compare ft_strcmp ft_memchr ft_striteri \
		ft_tolower  ft_strlen ft_putstr_fd ft_strlcat ft_calloc ft_strtrim \
		ft_toupper ft_isalnum ft_strrchr ft_str_not_in strlen_var ft_strlcpy ft_memcmp ft_split \
		ft_isalpha ft_memcpy ft_putnbr_fd ft_strnstr ft_strjoin \
		ft_isascii ft_memmove ft_strchr ft_strdup ft_strdupdup ft_substr \
		ft_lstiter ft_lstsize ft_lstclear ft_lstdelone ft_lstadd_back \
		ft_lstnew ft_lstadd_front two_d_strjoin ft_lstmap freed_strjoin ft_free ft_lstlast\
		ft_realloc ft_strjoinfree ft_freetab ft_charjoin ft_tablen ft_tabmaxlen get_next_line)
		
UTILS	= $(addprefix utils/, ft_error name_check read_map split_map free_cart draw_utile)
GAME	= $(addprefix game/, game position quit update keys move turn draw hcast vcast\
			gun ray ft_3d ft_ray ft_init ft_init2 ft_init3 textur)
CHECK	= $(addprefix check/, check00 check01)
PARSING = $(addprefix parsing/, parsing check_lines1 p_utils/mini_utils\
		p_utils/first_part_lines check_colors accessible  map_checker/check_map \
		map_checker/check_content map_checker/map_utils1)

FILES	= $(addprefix Mandatory/, main $(LIBFT) $(UTILS) $(CHECK) $(GAME) $(PARSING))
SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER  = Mandatory/include/cub3d.h
INCLUDES= -I Mandatory/include

LIBFT_B = $(addprefix  libft_bonus/, ft_isdigit ft_memset  ft_isprint ft_putendl_fd ft_itoa ft_strmapi \
		ft_bzero ft_putchar_fd  ft_atoi ft_strncmp var_compare ft_strcmp ft_memchr ft_striteri \
		ft_tolower  ft_strlen ft_putstr_fd ft_strlcat ft_calloc ft_strtrim \
		ft_toupper ft_isalnum ft_strrchr ft_str_not_in strlen_var ft_strlcpy ft_memcmp ft_split \
		ft_isalpha ft_memcpy ft_putnbr_fd ft_strnstr ft_strjoin \
		ft_isascii ft_memmove ft_strchr ft_strdup ft_strdupdup ft_substr \
		ft_lstiter ft_lstsize ft_lstclear ft_lstdelone ft_lstadd_back \
		ft_lstnew ft_lstadd_front two_d_strjoin ft_lstmap freed_strjoin ft_free ft_lstlast\
		ft_realloc ft_strjoinfree ft_freetab ft_charjoin ft_tablen ft_tabmaxlen get_next_line)
		
UTILS_B	= $(addprefix utils_bonus/, ft_error name_check read_map split_map free_cart draw_utile)
GAME_B	= $(addprefix game_bonus/, game position quit update keys move turn draw hcast vcast\
			gun ray ft_3d ft_ray ft_init ft_init2 ft_init3 textur)
CHECK_B	= $(addprefix check_bonus/, check00 check01)
PARSING_B = $(addprefix parsing_bonus/, parsing check_lines1 p_utils/mini_utils\
		p_utils/first_part_lines check_colors accessible  map_checker/check_map \
		map_checker/check_content map_checker/map_utils1)

FILES_B	= $(addprefix Bonus/, main $(LIBFT_B) $(UTILS_B) $(CHECK_B) $(GAME_B) $(PARSING_B))
SRC_B	= $(FILES_B:=_bonus.c)
OBJ_B	= $(FILES_B:=_bonus.o)
HEADER_B  = Bonus/include_bonus/cub3d_bonus.h
INCLUDES_B= -I Bonus/include_bonus

GREEN		=	\e[92;5;118m
RED			=	\e[0;31m
GRAY		=	\e[33;2;37m
CURSIVE		=	\e[33;3m
RESET		=	\e[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY)	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) $(INCLUDES) $(FRAMEWORKS) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@$(CC) -g $(FLAGS) $(INCLUDES)  -c $< -o $@ 

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B) $(HEADER_B)
	@printf "$(CURSIVE)$(GRAY)	- Compiling $(NAME_B)... $(RESET)\n"
	@$(CC) $(OBJ_B) $(INCLUDES_B) $(FRAMEWORKS) -o $(NAME_B)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%_bonus.o: %_bonus.c $(HEADER_B)
	@$(CC) $(FLAGS) $(INCLUDES_B)  -c $< -o $@ 
	
clean:
	@$(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(RED)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(RED)    - Executable removed.$(RESET)\n"

re: fclean all

bclean:
	@$(RM) $(OBJ_B) 
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(RED)    - Object files removed.$(RESET)\n"

bfclean: bclean
	@$(RM) $(NAME_B) 
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME_B) ... $(RESET)\n"
	@printf "$(RED)    - Executable removed.$(RESET)\n"

bre: bfclean bonus

.PHONY: all clean fclean re bonus bclean bfclean bre