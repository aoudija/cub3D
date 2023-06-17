/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:46:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 21:55:31 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	free_parser(void)
{
	free(g_data.pars.path_ea);
	free(g_data.pars.path_so);
	free(g_data.pars.path_no);
	free(g_data.pars.path_we);
	ft_free(g_data.pars.f);
	ft_free(g_data.pars.c);
	ft_free(g_data.pars.map);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (parsing(av[1]))
		{
			g_data.no.img = 0;
			g_data.no.img_w = 0;
			g_data.no.img_h = 0;
			g_data.no.addr = 0;
			g_data.frame1 = 0;
			g_data.shotf = 0;
			game();
			free_parser();
		}
	}
	return (0);
}
