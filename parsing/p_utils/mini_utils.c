/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:05:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/16 17:58:21 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	player_pos()
{
	int	i;
	int	j;

	i = -1;
	while (g_parser->map[++i])
	{
		j = -1;
		while (g_parser->map[i][++j])
		{
			if (g_parser->map[i][j] == 'N' || g_parser->map[i][j] == 'S'
				|| g_parser->map[i][j] == 'E' || g_parser->map[i][j] == 'W')
				g_parser->pos = g_parser->map[i][j];
		}
	}
}

int	end(char **file, char *str)
{
	int	e;

	e = lines_number(str);
	e--;
	while (all_white(file[e]))
		e--;
	return (e);
}

int	lines_number(char *str)
{
	char	*s;
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDWR);
	s = get_next_line(fd);
	while (s)
	{
		++i;
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
	return (i);
}

int all_white(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
	}
	return(1);
}

int dot_cub(char *str)
{
	if (ft_strcmp(str + (ft_strlen(str) - ft_strlen(".cub"))
		, ".cub") || open(str, O_RDWR) < 0)
	{
		printf("Error\nfile_err\n");
		return (0);
	}
	return (1);
}
