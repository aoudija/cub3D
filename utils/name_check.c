/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:49:58 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/16 21:40:21 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	name_check(char *name)
{
	int		namelen;
	char	*str;

	namelen = ft_strlen(name);
	if (namelen <= 4)
		ft_error("ERROR!\nThe map name has to ended with .cub extention.\n");
	str = name + (namelen - 4);
	if (ft_strcmp(str, ".cub"))
		ft_error("ERROR!\nThe map name has to ended with .cub extention.\n");
	return (0);
}
