/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:43:53 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/16 21:45:08 by aoudija          ###   ########.fr       */
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
	if (ac == 2)
	{
		g_parser = malloc(sizeof(t_pars));
		if (!parsing(av[1]))
			return (0);
		free_parser();
	}
}
