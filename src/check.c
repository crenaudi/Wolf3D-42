/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:27:43 by padelord          #+#    #+#             */
/*   Updated: 2020/05/10 01:23:28 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

int			check_border(int x, int y, int **map)
{
	int		i;

	i = -1;
	while (++i < y)
	{
		if (map[i][0] == 0 || map[i][x] == 0)
			return (0);
	}
	i = -1;
	while (++i < x)
	{
		if (map[0][i] == 0 || map[y][i] == 0)
			return (0);
	}
	return (1);
}

int		check_param(char *path, char *ext)
{
	t_u32	sp;
	t_u32	se;

	sp = ft_strlen(path);
	se = ft_strlen(ext);
	if (sp < se)
		return (0);
	return (!(ft_strcmp(path + sp - se, ext)));
}

void	check_player(t_env *e)
{
	int	x;
	int	y;

	if (e->map->size_x < 3 || e->map->size_y < 3)
		wolf3d_error(e, 1 | (1 << 16),
			"map too short, x and y must be greater than 3");
	y = 0;
	while (y < e->map->size_y - 1)
	{
		x = 0;
		while (x < e->map->size_x - 1)
		{
			if (e->map->data[y][x] == 0)
			{
				e->player->pos_y = y;
				e->player->pos_x = x;
				e->player->coord_x = (float)(e->player->pos_x) + 0.5;
				e->player->coord_y = (float)(e->player->pos_y) + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
	wolf3d_error(e, 1 | (1 << 16), "no block for player");
}
