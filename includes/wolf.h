/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 18:18:36 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 14:23:23 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H

# define WOLF_H

# define WIDTH		1000
# define HEIGHT		800
# define Y_SCREEN	700
# define X_SCREEN	1000
# define Y_MDDL		350
# define X_MDDL		500

# define EPSILON	0.006f
# define ALPHA_0	0xE6007E
# define DIST		0.2f
# define BLOCKS		64.f
# define TWOPI		6.2831854
# define TEX_WALL	64
# define DIST		0.2f

# define API		3.1415927
# define API_4		0.7853982
# define API_34		2.3561945

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "libgfx_includes/gfx.h"

typedef struct s_env	t_env;
typedef struct s_glob	t_glob;
typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_ray	t_ray;
typedef unsigned int	t_u32;

struct			s_ray
{
	int			map_x;
	int			map_y;
	float		hit_x;
	float		hit_y;
	float		tex_x;
	float		tex_y;
	float		bloc_mx;
	float		bloc_my;
	float		bloc_angle;
	t_vecf2		ray;
	float		dir_x;
	float		dir_y;
	t_vecf2		ray_dist;
	float		ray_angle;
	int			hit;
	int			nbw;
};

struct			s_map
{
	int			size_x;
	int			size_y;
	int			width_screen;
	int			height_screen;
	int			**data;
};

struct			s_player
{
	int			pos_x;
	int			pos_y;
	float		coord_x;
	float		coord_y;
	float		eyes_dir;
	int			level;
	int			score;
	int			arms;
	int			pv;
};

struct			s_glob
{
	t_map		map;
	t_cam2d		cam;
	t_player	player;
};

struct			s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_img		*legend;
	t_u32		*pal;
	t_player	*player;
	t_cam2d		*cam;
	t_map		*map;
	t_sprite	*head;
	t_sprite	*cut;
	t_glob		global;
	t_img		*srcs[2];
	t_texture	*wall[4];
	int			nsrc;
	int			key_right;
	int			key_left;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_shoot;
	float		half_yscreen;
};

int				run(t_env *e);
void			legend(t_env *e);
int				key_press(int key, t_env *e);
int				key_release(int key, t_env *e);
void			init_env(t_env *e);
void			init_global(t_glob *global);
t_player		init_player();
void			init_texture(t_env *e);
t_map			init_map();
int				map_int(t_env *e, int fd);
void			putpx(t_img *img, t_vec2 i, int height, int color);
void			free_secure(void *ptr);
void			wolf3d_error(t_env *e, unsigned int err, char *line);
void			dda_info_txtur(t_ray *r, t_player *p);
int				dda_ray(t_ray *r, t_player *p, t_map *map);
int				ray_cast(t_env *e, t_cam2d *c);
void			draw_wall(t_env *e, t_ray r, int x[3], float draw[2]);
void			check_move(t_env *e);
t_vecf2			get_newpos(t_vecf2 dir, t_vecf2 coord, t_map map);
int				move_player(t_player *plr, t_vec2 dir, t_map map, float speed);
void			clean(t_env *e);
void			clean_tab(int **map, int y);

#endif
