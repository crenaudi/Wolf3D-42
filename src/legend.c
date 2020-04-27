/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:39:42 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 20:32:13 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		put_px(t_img *img, int x, int y, int color)
{
	int		index;

	index = x + y * WIDTH;
	if (index < 0 || index >= HEIGHT * WIDTH)
		return ;
	img->data[index] = color;
}

static void		color_box(int height, int x_start, int width, t_img *img)
{
	int		x;
	int		y;
	int		y_border;

	y_border = 2;
	y = -1;
	while (++y < height)
	{
		x = x_start - 1;
		while (++x < width)
		{
			if (y < y_border || x < x_start + 3)
				put_px(img, x, y, 0xAF1FAEE);
			else if ((y <= y_border + 2 || x <= x_start + 4))
				put_px(img, x, y, 0x000000);
			else
				put_px(img, x, y, 0x0530AD);
		}
	}
}

static void		lgd_txt(void *mptr, void *wptr, t_player *player, int pos_y)
{
	char *s;

	s = NULL;
	mlx_string_put(mptr, wptr, 30, pos_y + 25, 0xFFFFFF, "LEVEL");
	s = ft_itoa(player->level);
	mlx_string_put(mptr, wptr, 30, pos_y + 50, 0xFFFFFF, s);
	free_secure(s);
	mlx_string_put(mptr, wptr, 180, pos_y + 25, 0xFFFFFF, "SCORE");
	s = ft_itoa(player->score);
	mlx_string_put(mptr, wptr, 180, pos_y + 50, 0xFFFFFF, s);
	free_secure(s);
	mlx_string_put(mptr, wptr, 330, pos_y + 25, 0xFFFFFF, "HEALTH");
	s = ft_itoa(player->pv);
	mlx_string_put(mptr, wptr, 330, pos_y + 50, 0xFFFFFF, s);
	free_secure(s);
	mlx_string_put(mptr, wptr, 580, pos_y + 25, 0xFFFFFF, "ARMS");
	s = ft_itoa(player->arms);
	mlx_string_put(mptr, wptr, 580, pos_y + 50, 0xFFFFFF, s);
	free_secure(s);
	mlx_string_put(mptr, wptr, 680, pos_y + 15, 0xFFFFFF, "FORWARD..W");
	mlx_string_put(mptr, wptr, 680, pos_y + 40, 0xFFFFFF, "BACK.....S");
	mlx_string_put(mptr, wptr, 680, pos_y + 65, 0xFFFFFF, "RIGHT....D");
	mlx_string_put(mptr, wptr, 805, pos_y + 65, 0xFFFFFF, "LEFT...A");
	mlx_string_put(mptr, wptr, 805, pos_y + 15, 0xFFFFFF, "SHOOT..(enter)");
	mlx_string_put(mptr, wptr, 805, pos_y + 40, 0xFFFFFF, "TAKE...(space)");
}

void			legend(t_env *e)
{
	int	x;
	int	pos_y;

	x = 100;
	pos_y = 700;
	color_box(x, 0, 150, e->legend);
	color_box(x, 150, 300, e->legend);
	color_box(x, 300, 450, e->legend);
	color_box(x, 550, 650, e->legend);
	color_box(x, 650, WIDTH, e->legend);
	color_box(x, 450, 550, e->legend);
	apply_sprite(e->head, e->legend);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->legend->ptr, 0, pos_y);
	lgd_txt(e->mlx_ptr, e->win_ptr, e->player, pos_y);
}
