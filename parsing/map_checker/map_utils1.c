/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:45:04 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/16 17:56:27 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int	map_len(void)
{
	int	i;

	i = 0;
	while (g_parser->map[i])
		i++;
	return (i);
}

int	check_first_last(void)
{
	int	i;
	int	e;

	i = -1;
	while (g_parser->map[0][++i])
	{
		if (g_parser->map[0][i] == '0'
			|| g_parser->map[0][i] == g_parser->pos)
			return (0);
	}
	e = map_len() - 1;
	i = -1;
	while (g_parser->map[e][++i])
	{
		if (g_parser->map[e][i] == '0'
			|| g_parser->map[e][i] == g_parser->pos)
			return (0);
	}
	return (1);
}
