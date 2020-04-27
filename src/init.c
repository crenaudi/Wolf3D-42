/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:44:55 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 21:44:48 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_map		init_map(void)
{
	t_map	mp;

	mp.size_x = 0;
	mp.size_y = 0;
	mp.width_screen = 0;
	mp.height_screen = 0;
	mp.data = NULL;
	return (mp);
}

t_player	init_player(void)
{
	t_player	p;

	p.pos_y = 2;
	p.pos_x = 1;
	p.coord_x = (float)(p.pos_x) + 0.5;
	p.coord_y = (float)(p.pos_y) + 0.5;
	p.eyes_dir = 0.0f;
	p.level = 1;
	p.score = 0;
	p.pv = 100;
	p.arms = 1;
	return (p);
}

void		init_global(t_glob *global)
{
	t_cam2d		c;
	t_player	p;
	t_map		mp;

	c = init_cam2d();
	p = init_player();
	mp = init_map();
	global->map = mp;
	global->cam = c;
	global->player = p;
}

t_u32		*base_pal(void)
{
	t_u32	*pal;
	int		i;
	float	t;

	if (!(pal = malloc(sizeof(int) * Y_SCREEN)))
		return (0);
	t = 0;
	i = -1;
	while (++i < Y_SCREEN)
	{
		if (i >= Y_MDDL)
			t = i / (float)Y_SCREEN;
		if (i < Y_MDDL)
			pal[i] = 0x383838;
		else
			pal[i] = lerp_non_init_color(0x000000, 0x606D5D, t);
	}
	return (pal);
}

void		init_env(t_env *e)
{
	ft_bzero(e, sizeof(*e));
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "Wolf3D");
	if (!(e->srcs[0] = init_image(e->mlx_ptr, X_SCREEN, Y_SCREEN)))
		wolf3d_error(e, 0 ^ (1 << 16), "srcs[0] init.c line 71");
	if (!(e->srcs[1] = init_image(e->mlx_ptr, X_SCREEN, Y_SCREEN)))
		wolf3d_error(e, 0 ^ (1 << 16), "srcs[1] init.c line 73");
	e->img = e->srcs[0];
	e->nsrc = 0;
	if (!(e->legend = init_image(e->mlx_ptr, WIDTH, 100)))
		wolf3d_error(e, 0 ^ (1 << 16), "legend init.c line 77");
	if ((e->pal = base_pal()) == 0)
		wolf3d_error(e, 3, "e->pal init.c line 79");
	e->map = &(e->global.map);
	e->cam = &(e->global.cam);
	e->player = &(e->global.player);
	init_texture(e);
	init_global(&e->global);
	e->key_right = 0;
	e->key_left = 0;
	e->key_w = 0;
	e->key_s = 0;
	e->key_a = 0;
	e->key_d = 0;
	e->half_yscreen = (float)(Y_SCREEN) / 2.f;
	legend(e);
}
