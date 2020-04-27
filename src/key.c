/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:44:39 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 14:55:08 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		key_press(int key, t_env *e)
{
	int		move_speed;

	move_speed = 1;
	if (key == K_ARIGHT)
		e->key_right = 1;
	if (key == K_ALEFT)
		e->key_left = 1;
	if (key == K_W)
		e->key_w = 1;
	if (key == K_S)
		e->key_s = 1;
	if (key == K_A)
		e->key_a = 1;
	if (key == K_D)
		e->key_d = 1;
	if (key == K_SPC)
		e->key_shoot = 1;
	if (key == K_ESC)
	{
		clean(e);
		exit(0);
	}
	return (SUCCESS);
}

int		key_release(int key, t_env *e)
{
	int		move_speed;

	move_speed = 1;
	if (key == K_ARIGHT)
		e->key_right = 0;
	if (key == K_ALEFT)
		e->key_left = 0;
	if (key == K_W)
		e->key_w = 0;
	if (key == K_S)
		e->key_s = 0;
	if (key == K_A)
		e->key_a = 0;
	if (key == K_D)
		e->key_d = 0;
	if (key == K_SPC)
		e->key_shoot = 0;
	if (key == K_ESC)
	{
		clean(e);
		exit(0);
	}
	return (SUCCESS);
}
