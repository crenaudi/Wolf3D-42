/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:25:10 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/24 18:13:39 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	init_texture(t_env *e)
{
	if (!(e->wall[0] = init_tx(e->mlx_ptr, "src/ressources/wall1.xpm",
		(t_vec2){128, 128}, 8)))
		wolf3d_error(e, 2 ^ (1 << 16), "wall 0 init.c line 85");
	if (!(e->wall[1] = init_tx(e->mlx_ptr, "src/ressources/wall2.xpm",
		(t_vec2){128, 128}, 8)))
		wolf3d_error(e, 2 ^ (1 << 16), "wall 1 init.c line 87");
	if (!(e->wall[2] = init_tx(e->mlx_ptr, "src/ressources/wall3.xpm",
		(t_vec2){128, 128}, 8)))
		wolf3d_error(e, 2 ^ (1 << 16), "wall 2 init.c line 89");
	if (!(e->wall[3] = init_tx(e->mlx_ptr, "src/ressources/wall4.xpm",
		(t_vec2){128, 128}, 8)))
		wolf3d_error(e, 2 ^ (1 << 16), "wall 3 init.c line 91");
	if (!(e->head = init_sprite(init_tx(e->mlx_ptr, "src/ressources/fhead.xpm",
		(t_vec2){100, 100}, 3), 0, 0, (t_vec2){(WIDTH - 100) / 2, 0})))
		wolf3d_error(e, 2 ^ (1 << 16), "head init.c line 93");
	if (!(e->cut = init_sprite(init_tx(e->mlx_ptr, "src/ressources/cut.xpm",
		(t_vec2){128, 128}, 4), SPRIT_ISANIM, 20, (t_vec2){(WIDTH - 256) / 2,
			Y_SCREEN - 256})))
		wolf3d_error(e, 2 ^ (1 << 16), "initCut init.c line 95");
	if (!(e->cut->tx = tx_scaleby(e->mlx_ptr, e->cut->tx, 2.0)))
		wolf3d_error(e, 2 ^ (1 << 16), "scaleCut init.c line 97");
}
