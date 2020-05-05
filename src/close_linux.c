/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:47:42 by crenaudi          #+#    #+#             */
/*   Updated: 2020/05/02 03:54:10 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	free_secure(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	else
		ft_putendl("Free sur ptr NULL");
}

void		close_map(t_map **map)
{
	int		i;
	t_map	*p;

	if (map && *map)
	{
		p = *map;
		i = -1;
		while (++i < p->size_y)
		{
			if (p->data[i])
			{
				ft_bzero(p->data[i], sizeof(int) * p->size_x);
				free(p->data[i]);
			}
		}
		ft_bzero(p->data, sizeof(int*) * p->size_y);
		free(p->data);
		ft_bzero(p, sizeof(*p));
		*map = 0;
	}
}

void	clean(t_env *e)
{
	close_map(&(e->map));
	close_image(e->srcs[0], e->mlx_ptr, X_SCREEN, Y_SCREEN);
	close_image(e->srcs[1], e->mlx_ptr, X_SCREEN, Y_SCREEN);
	close_image(e->legend, e->mlx_ptr, WIDTH, 100);
	close_sprite(&(e->cut));
	close_sprite(&(e->head));
	close_tx(&(e->wall[0]));
	close_tx(&(e->wall[1]));
	close_tx(&(e->wall[2]));
	close_tx(&(e->wall[3]));
	free_secure(e->pal);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	ft_putendl("A bientot !");
	mlx_destroy(e->mlx_ptr);
	ft_bzero(e, sizeof(t_env));
	exit(0);
}
