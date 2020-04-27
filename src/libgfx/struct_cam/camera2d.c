/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 18:32:09 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 14:38:19 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libgfx_includes/gfx.h"

t_cam2d		init_cam2d(void)
{
	t_cam2d		c;

	clean_cam2d(&c);
	c.fov = 3.1415927 / 3;
	c.half_fov = c.fov / 2.0f;
	c.speed_move = 100.;
	c.speed_angle = 100.;
	return (c);
}

void		clean_cam2d(t_cam2d *c)
{
	ft_bzero(c, sizeof(t_cam2d));
}
