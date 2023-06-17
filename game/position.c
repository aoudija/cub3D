/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:05:51 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/16 21:40:21 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	position(void)
{
	int		i;
	int		j;

	i = 0;
	while (g_data.cart[i])
	{
		j = 0;
		while (g_data.cart[i][j])
		{
			if (g_data.cart[i][j] == 'P')
			{
				g_data.player.x = j * CUBE + CUBE / 2;
				g_data.player.y = i * CUBE + CUBE / 2;
			}
			j++;
		}
		i++;
	}
}
