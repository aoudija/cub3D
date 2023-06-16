# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 14:44:25 by aoudija           #+#    #+#              #
#    Updated: 2023/06/16 21:47:54 by aoudija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

FLAGS = -g  -Wall -Wextra -Werror

mlx_FLAGS = -lmlx -framework OpenGL -framework AppKit

DEPS = cube.h

AMINE = main get_next_line/get_next_line parsing/parsing parsing/check_lines1 \
		parsing/p_utils/mini_utils parsing/p_utils/first_part_lines parsing/check_colors \
		parsing/accessible  parsing/map_checker/check_map parsing/map_checker/check_content \
		parsing/map_checker/map_utils1\

FILES = $(AMINE) $(LIBFT)

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER  = cube.h

all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY)	- Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) $(mlx_FLAGS) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@$(CC) -g $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re
