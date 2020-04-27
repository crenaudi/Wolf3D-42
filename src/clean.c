/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:47:42 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 16:00:01 by crenaudi         ###   ########.fr       */
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

void	clean(t_env *e)
{
	close_image(e->srcs[0], e->mlx_ptr, X_SCREEN, Y_SCREEN);
	close_image(e->srcs[1], e->mlx_ptr, X_SCREEN, Y_SCREEN);
	close_image(e->legend, e->mlx_ptr, WIDTH, 100);
	close_sprite(&(e->cut));
	close_sprite(&(e->head));
	close_tx(&(e->wall[0]));
	close_tx(&(e->wall[1]));
	close_tx(&(e->wall[2]));
	close_tx(&(e->wall[3]));
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	ft_bzero(e, sizeof(t_env));
	ft_putendl("A bientot !");
	exit(0);
}
