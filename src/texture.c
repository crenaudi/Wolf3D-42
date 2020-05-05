/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:25:10 by crenaudi          #+#    #+#             */
/*   Updated: 2020/05/02 04:17:39 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	init_texture(t_env *e)
{
	if (!(e->wall[0] = init_tx("src/ressources/wall1.wtx",
		(t_vec2){128, 128}, 8)))
		wolf3d_error(e, 2 ^ (1 << 16), "wall 0 init.c line 85");
	if (!(e->wall[1] = init_tx("src/ressources/wall2.wtx",
		(t_vec2){128, 128}, 8)))
		wolf3d_error(e, 2 ^ (1 << 16), "wall 1 init.c line 87");
	if (!(e->wall[2] = init_tx("src/ressources/wall3.wtx",
		(t_vec2){128, 128}, 8)))
		wolf3d_error(e, 2 ^ (1 << 16), "wall 2 init.c line 89");
	if (!(e->wall[3] = init_tx("src/ressources/wall4.wtx",
		(t_vec2){128, 128}, 8)))
		wolf3d_error(e, 2 ^ (1 << 16), "wall 3 init.c line 91");
	if (!(e->head = init_sprite(init_tx("src/ressources/fhead.wtx",
		(t_vec2){100, 100}, 3), 0, 0, (t_vec2){(WIDTH - 100) / 2, 0})))
		wolf3d_error(e, 2 ^ (1 << 16), "head init.c line 93");
	if (!(e->cut = init_sprite(init_tx("src/ressources/cut.wtx",
		(t_vec2){128, 128}, 4), SPRIT_ISANIM, 20, (t_vec2){(WIDTH - 256) / 2,
			Y_SCREEN - 256})))
		wolf3d_error(e, 2 ^ (1 << 16), "initCut init.c line 95");
	if (!(e->cut->tx = tx_scaleby(e->cut->tx, 2.0)))
		wolf3d_error(e, 2 ^ (1 << 16), "scaleCut init.c line 97");
}
