/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:39:01 by crenaudi          #+#    #+#             */
/*   Updated: 2020/05/09 20:46:52 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int		fx_close_hook(void *param)
{
	clean((t_env*)param);
	return (1);
}

void			putpx(t_img *img, t_vec2 i, int h, int color)
{
	int	index;

	index = i.x + i.y * WIDTH;
	if (index < 0 || index >= h * WIDTH)
		return ;
	img->data[index] = color;
}

void			color_base(t_img *img, t_u32 *pal)
{
	t_vec2	size;
	t_u32	*tab;
	t_vec2	i;

	size = img->size;
	tab = (t_u32*)img->data;
	i.y = -1;
	while (++i.y < size.y)
	{
		i.x = -1;
		while (++i.x < size.x)
			*tab++ = pal[i.y];
	}
}

int				run(t_env *e)
{
	check_move(e);
	if (e->pal != 0)
		color_base(e->img, e->pal);
	ray_cast(e, e->cam);
	apply_sprite(e->cut, e->img);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img->ptr, 0, 0);
	legend(e);
	if (e->nsrc)
		e->img = e->srcs[0];
	else
		e->img = e->srcs[1];
	e->nsrc = !e->nsrc;
	return (SUCCESS);
}

int				main(int argc, char **argv)
{
	t_env	e;
	int		fd;

	if (argc != 2)
	{
		ft_putendl("Wrong map");
		return (0);
	}
	if (!(fd = open(argv[1], O_RDONLY | O_NOFOLLOW | O_NOCTTY)))
	{
		wolf3d_error(NULL, 1, "Wrong file");
		return (0);
	}
	ft_bzero((void *)&e, sizeof(t_env));
	init_env(&e);
	if (map_int(&e, fd) == ERROR)
		wolf3d_error(&e, 1 ^ (1 << 16), "parse error");
	mlx_loop_hook(e.mlx_ptr, run, &e);
	mlx_hook(e.win_ptr, 2, (1L << 0), key_press, &e);
	mlx_hook(e.win_ptr, 3, (1L << 1), key_release, &e);
	mlx_hook(e.win_ptr, 17, (1L << 17), fx_close_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
