/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:12:29 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/16 21:40:21 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	vapsangle(double *angle)
{
	*angle = fmod(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle += 2 * M_PI;
}

void	turn_left(t_data *data, int flag)
{
	g_data.player.dirturn = 1;
	if (flag)
		g_data.player.alpha += g_data.player.dirturn
			* g_data.player.speedretate_m;
	else
		g_data.player.alpha += g_data.player.dirturn
			* g_data.player.speedretate;
	vapsangle(&g_data.player.alpha);
}

void	turn_right(t_data *data, int flag)
{
	g_data.player.dirturn = -1;
	if (flag)
		g_data.player.alpha += g_data.player.dirturn
			* g_data.player.speedretate_m;
	else
		g_data.player.alpha += g_data.player.dirturn
			* g_data.player.speedretate;
	vapsangle(&g_data.player.alpha);
}
