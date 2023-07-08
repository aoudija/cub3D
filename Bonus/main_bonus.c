/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:46:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/07/08 16:01:20 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_bonus/cub3d_bonus.h"

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
			game();
	}
	else
		printerr(6);
	return (0);
}
