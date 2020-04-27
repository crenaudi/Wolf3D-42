/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:46:47 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 15:59:16 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int	add_dist(t_ray ray)
{
	int dist;

	dist = (int)((ray.ray_dist.x * ray.ray_dist.x
		+ ray.ray_dist.y * ray.ray_dist.y));
	if (dist < 0)
		dist = 0;
	dist >>= 6;
	return (dist);
}

static void	add_gap_orig(float draw[2], float *gap, float *orig)
{
	int		sub;

	sub = (int)(draw[1] - draw[0]);
	*gap = 128.f / (float)sub;
	*orig = (sub > Y_SCREEN) ? draw[0] * -1 * *gap : 0;
}

void		draw_wall(t_env *e, t_ray ray, int i[3], float draw[2])
{
	float	gap;
	float	orig;
	int		dx;
	int		dist;
	t_u32	*tx;

	dx = ray.tex_x * 128;
	dist = add_dist(ray);
	add_gap_orig(draw, &gap, &orig);
	i[1] = (draw[0] > 0) ? draw[0] : 0;
	if (dist <= 7)
		tx = e->wall[ray.nbw]->frames[dist];
	while (i[1] < i[2])
	{
		orig += gap;
		if (orig > 128.f)
			orig = 128.f;
		if (dist > 7)
			putpx(e->img, (t_vec2){i[0], i[1]}, Y_SCREEN, 0x000000);
		else
			putpx(e->img, (t_vec2){i[0], i[1]}, Y_SCREEN,
					tx[(int)(orig) * 128 + dx]);
		i[1]++;
	}
	ft_bzero(&ray, sizeof(t_ray));
}
