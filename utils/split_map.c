/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:12:08 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/07 16:51:38 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**split_map(char *map)
{
	char	**p;

	if (!map)
		return (0);
	p = ft_split(map, '\n');
	return (p);
}
