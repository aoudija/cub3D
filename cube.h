/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:51:09 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/16 21:41:17 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "mlx.h"

char	*get_next_line(int fd);
//pasing

typedef struct	s_pars
{
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	*colorf;
	char	*colorc;
	char	**f;
	char	**c;
	char	**map;
	char	pos;
}				t_pars;
t_pars	*g_parser;
int		parsing(char *str);
int		dot_cub(char *arg);
int 	all_white(char *str);
int		check_lines(char *str);
char	*get_line(char **tab, char *str);
char	*rest_of_line(char *line, char *str);
char	*get_str(char *str);
int		check_colors(void);
int		accessible(void);
char	**file_tab(char *str);
char	**fst_part(char **tab);
int		checker_map1(char *str);
int		lines_number(char *str);
int		check_content(void);
void	printerr(int e);
void	player_pos();
int		end(char **file, char *str);
int		map_len(void);
int		check_first_last(void);

#endif