/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:24:53 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/16 14:18:36 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int	skip_part1(char **tab)
{
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (tab[++i] && c < 6)
	{
		if ((tab[i][0] == ' ' || tab[i][0] == '\t') && !all_white(tab[i]))
			c++;
		else if ((tab[i][0] == ' ' || tab[i][0] == '\t') && all_white(tab[i]))
		{
		}
		else if (tab[i][0] != '\n' && ft_strlen(tab[i]) >= 1)
			c++;
	}
	return (i);
}

void	put_map(char  **file, char *str)
{
	int	i;
	int	j;
	int n;

	i = skip_part1(file);
	g_parser->map = malloc(sizeof(char *) * ((lines_number(str) - i ) + 1));
	j = 0;
	n = 0;
	while (file[i])
	{
		g_parser->map[j] = ft_strdup(file[i]);
		j++;
		i++;
	}
	g_parser->map[j] = NULL;
	ft_free(file);
}

int	is_closed(char c)
{
	int	i;
	int	j;

	i = -1;
	while (g_parser->map[++i])
	{
		j = -1;
		while (g_parser->map[i][++j])
		{
			if (g_parser->map[i][j] == c)
			{
				if (g_parser->map[i][j - 1] == ' ' || g_parser->map[i][j - 1] == 0)
					return (0);
				if (g_parser->map[i][j + 1] == ' ' || g_parser->map[i][j + 1] == 0)
					return (0);
				if (g_parser->map[i - 1][j] == ' ' || g_parser->map[i - 1][j] == 0)
					return (0);
				if (g_parser->map[i + 1][j] == ' ' || g_parser->map[i + 1][j] == 0)
					return (0);
			}
		}
	}
	return (1);
}

int	checker_map1(char *str)
{
	int		i;

	put_map(file_tab(str), str);
	if (!check_content())
		return (0);
	player_pos();
	if (!is_closed(g_parser->pos) || !is_closed('0'))
		return (0);
	return (1);
}
