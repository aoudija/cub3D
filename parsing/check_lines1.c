/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:32:15 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/16 21:21:39 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	**file_tab(char *str)
{
	int		i;
	int		fd;
	char	*line;
	char	**file;

	file = malloc(sizeof(char *) * lines_number(str) + 1);
	fd = open(str, O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		file[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	file[i] = 0;
	return (file);
}

char	**fst_part(char **tab)
{
	char	**fst_part;
	int		i;
	int		j;
	int		c;

	fst_part = malloc (sizeof(char *) * 6 + 1);
	i = -1;
	j = -1;
	c = 0;
	while (tab[++i] && c < 6)
	{
		if ((tab[i][0] == ' ' || tab[i][0] == '\t') && !all_white(tab[i]))
			(fst_part[++j] = ft_strdup(tab[i]), c++);
		else if ((tab[i][0] == ' ' || tab[i][0] == '\t') && all_white(tab[i]))
		{
		}
		else if (tab[i][0] != '\n' && ft_strlen(tab[i]) >= 1)
			(fst_part[++j] = ft_strdup(tab[i]), c++);
	}
	fst_part[++j] = 0;
	return (fst_part);
}

int	paths(char **lines)
{
	char *t;

	t = rest_of_line(get_line(lines, "NO"), "NO");
	if (!t)
		return (0);
	free(t);
	g_parser->path_no = get_str(rest_of_line(get_line(lines, "NO"), "NO"));
	t = rest_of_line(get_line(lines, "SO"), "SO");
	if (!t)
		return (free(g_parser->path_no), 0);
	free(t);
	g_parser->path_so = get_str(rest_of_line(get_line(lines, "SO"), "SO"));
	t = rest_of_line(get_line(lines, "WE"), "WE");
	if (!t)
		return (free(g_parser->path_no), free(g_parser->path_so), 0);
	free(t);
	g_parser->path_we = get_str(rest_of_line(get_line(lines, "WE"), "WE"));
	t = rest_of_line(get_line(lines, "EA"), "EA");
	if (!t)
		return (free(g_parser->path_no), free(g_parser->path_so),
			free(g_parser->path_we), 0);
	free(t);
	g_parser->path_ea = get_str(rest_of_line(get_line(lines, "EA"), "EA"));
	return (1);
}

int	colors(char **lines)
{
	char	*t;

	t = rest_of_line(get_line(lines, "F"), "F");
	if (!t)
		return (0);
	free(t);
	g_parser->colorf = get_str(rest_of_line(get_line(lines, "F"), "F"));
	t = rest_of_line(get_line(lines, "C"), "C");
	if (!t)
		return (free(g_parser->colorf), 0);
	free(t);
	g_parser->colorc = get_str(rest_of_line(get_line(lines, "C"), "C"));
	return (1);
}

int	check_lines(char *str)
{
	char	**file;
	char	**lines;

	file = file_tab(str);
	lines = fst_part(file);
	ft_free(file);
	if (!paths(lines))
		return (ft_free(lines), 0);
	if (!g_parser->path_ea || !g_parser->path_we
		|| !g_parser->path_so || !g_parser->path_no)
		return (ft_free(lines), 0);
	if (!colors(lines))
		return (ft_free(lines), free(g_parser->path_no),
			free(g_parser->path_so), free(g_parser->path_we),
			free(g_parser->path_ea), 0);
	return (ft_free(lines), 1);
}
