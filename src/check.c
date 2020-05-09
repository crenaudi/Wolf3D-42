/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:27:43 by padelord          #+#    #+#             */
/*   Updated: 2020/05/09 23:31:20 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"
#include <stdio.h>

int		check_param(char *path, char *ext)
{
	t_u32	sp;
	t_u32	se;

	if ((sp = ft_strlen(path)) < (se = ft_strlen(ext)))
		return (0);
	return (!(ft_strcmp(path + sp - se, ext)));
}

void	check_player(t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->map->size_y)
	{
		x = 0;
		while (x < e->map->size_x)
		{
			if (e->map->data[y][x] == 0)
			{
				e->player->pos_y += 1;
				e->player->pos_x += 1;
				e->player->coord_x = (float)(e->player->pos_x) + 0.5;
				e->player->coord_y = (float)(e->player->pos_y) + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
	wolf3d_error(e,  1 | (1 << 16), "no block for player");
}
