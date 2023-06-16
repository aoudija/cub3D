/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:46:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/16 21:47:10 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_parser(void)
{
	free(g_parser->path_ea);
	free(g_parser->path_so);
	free(g_parser->path_no);
	free(g_parser->path_we);
	ft_free(g_parser->f);
	ft_free(g_parser->c);
	ft_free(g_parser->map);
	free(g_parser);
}

int	main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		g_parser = malloc(sizeof(t_pars));
		if (!parsing(av[1]))
			return (0);
		g_data.no.img = 0;
		g_data.no.img_w = 0;
		g_data.no.img_h = 0;
		g_data.no.addr = 0;
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			ft_error("ERROR!\nPath map name invalid.\n");
		g_data.map = read_map(fd);
		if (!g_data.map || !ft_strncmp(g_data.map, "", 1))
			ft_error("ERROR!!\nMap invalid.\n");
		game();
		free_parser();
	}
	return (0);
}
