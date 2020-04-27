/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:36:21 by padelord          #+#    #+#             */
/*   Updated: 2020/04/24 18:14:57 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_vecf2			get_newpos(t_vecf2 dir, t_vecf2 coord, t_map map)
{
	t_vecf2	new;

	if (dir.x > 0.0 && map.data[(int)coord.y][(int)(coord.x + DIST)])
		dir.x = 0;
	else if (dir.x < 0.0 && map.data[(int)coord.y][(int)(coord.x - DIST)])
		dir.x = 0;
	if (dir.y > 0.0 && map.data[(int)(coord.y + DIST)][(int)coord.x])
		dir.y = 0;
	else if (dir.y < 0.0 && map.data[(int)(coord.y - DIST)][(int)coord.x])
		dir.y = 0;
	new = coord + dir;
	if (map.data[(int)new.y][(int)new.x] == 0)
		return (new);
	return (coord);
}

static float	get_angle(t_vec2 dir)
{
	if (dir.x && dir.y)
		return (((dir.x == 1) ? 1 : 3) * (API / 4) * (float)(dir.y));
	else if (dir.x)
		return (dir.x == 1 ? 0 : API);
	else
		return (API / 2.0 * (float)dir.y);
}

int				move_player(t_player *plr, t_vec2 dir, t_map map, float speed)
{
	t_vecf2		newpos;
	float		angle;

	if (!dir.x && !dir.y)
		return (ERROR);
	angle = get_angle(dir);
	newpos = (t_vecf2){cos(plr->eyes_dir + angle) * speed,
		-1 * sin(plr->eyes_dir + angle) * speed};
	newpos = get_newpos(newpos, (t_vecf2){plr->coord_x, plr->coord_y}, map);
	plr->coord_x = newpos.x;
	plr->coord_y = newpos.y;
	return (SUCCESS);
}

static void		move_rotation_head(t_env *e, float speed)
{
	if (e->key_right == 1)
	{
		e->head->cframe = 2;
		e->player->eyes_dir += speed;
		if (e->player->eyes_dir > TWOPI)
			e->player->eyes_dir -= TWOPI;
	}
	if (e->key_left == 1)
	{
		e->head->cframe = 1;
		e->player->eyes_dir -= speed;
		if (e->player->eyes_dir < 0)
			e->player->eyes_dir += TWOPI;
	}
	if (e->key_left == 0 && e->key_right == 0)
		e->head->cframe = 0;
}

void			check_move(t_env *e)
{
	t_vec2	dir;

	dir = 0;
	move_rotation_head(e, 0.06);
	if (e->key_w == 1)
		dir.y = -1;
	if (e->key_s == 1)
		dir.y = 1;
	if (e->key_a == 1)
		dir.x = -1;
	if (e->key_d == 1)
		dir.x = 1;
	if (e->key_shoot)
		trigger_sprite(e->cut);
	move_player(e->player, dir, *(e->map), 0.06);
}
