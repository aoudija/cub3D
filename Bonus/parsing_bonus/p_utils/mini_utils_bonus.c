/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:05:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/07/06 18:01:19 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	player_pos(void)
{
	int	i;
	int	j;

	i = -1;
	while (g_data.pars.map[++i])
	{
		j = -1;
		while (g_data.pars.map[i][++j])
		{
			if (g_data.pars.map[i][j] == 'N' || g_data.pars.map[i][j] == 'S'
				|| g_data.pars.map[i][j] == 'E' || g_data.pars.map[i][j] == 'W')
			{
				g_data.pars.pos = g_data.pars.map[i][j];
				g_data.pars.x = i;
				g_data.pars.y = j;
			}
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

int	all_white(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
	}
	return (1);
}

int	dot_cub(char *str)
{
	if (ft_strcmp(str + (ft_strlen(str) - ft_strlen(".cub")), ".cub")
		|| open(str, O_RDWR) < 0)
		return (0);
	return (1);
}
