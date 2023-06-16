/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:31:10 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/16 21:40:21 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	move_down(t_data *data)
{
	double	movespeed;
	double	x;
	double	y;

	data->player.dirwalk = -1;
	movespeed = data->player.dirwalk * data->player.speedmove;
	x = data->player.x + cos(data->player.alpha) * movespeed;
	y = data->player.y + sin(data->player.alpha) * movespeed;
	if (check_wall(x, y))
	{
		data->player.y = y;
		data->player.x = x;
	}
}

void	move_top(t_data *data)
{
	double	movespeed;
	double	x;
	double	y;

	data->player.dirwalk = 1;
	movespeed = data->player.dirwalk * data->player.speedmove;
	y = data->player.y + sin(data->player.alpha) * movespeed;
	x = data->player.x + cos(data->player.alpha) * movespeed;
	if (check_wall(x, y))
	{
		puts("hey\n");
		data->player.y = y;
		data->player.x = x;
	}
}

void	move_right(t_data *data)
{
	double	movespeed;
	double	x;
	double	y;

	data->player.dirwalk = -1;
	movespeed = data->player.dirwalk * data->player.speedmove;
	y = data->player.y + sin(data->player.alpha - M_PI_2) * movespeed;
	x = data->player.x + cos(data->player.alpha - M_PI_2) * movespeed;
	if (check_wall(x, y))
	{
		data->player.y = y;
		data->player.x = x;
	}
}

void	move_left(t_data *data)
{
	double	movespeed;
	double	x;
	double	y;

	data->player.dirwalk = 1;
	movespeed = data->player.dirwalk * data->player.speedmove;
	y = data->player.y + sin(data->player.alpha - M_PI_2) * movespeed;
	x = data->player.x + cos(data->player.alpha - M_PI_2) * movespeed;
	if (check_wall(x, y))
	{
		data->player.y = y;
		data->player.x = x;
	}
}
