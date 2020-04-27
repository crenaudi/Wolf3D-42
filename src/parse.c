/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:29:05 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 20:38:37 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		print_map(int **map, t_vec2 i)
{
	int	x;
	int	y;

	ft_putendl("Map :");
	y = -1;
	while (++y < i.y)
	{
		x = -1;
		while (++x < i.x)
		{
			if (map[y][x] == 0)
				ft_putchar('.');
			else
				ft_putchar('o');
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

static int		**compil_map(t_vec2 index, char *comp, int i)
{
	int **ord;
	int *abc;
	int x;
	int y;

	if (!(ord = (int **)malloc(sizeof(int *) * index.y)))
		return (NULL);
	y = -1;
	while (++y < index.y)
	{
		if (!(abc = (int *)malloc(sizeof(int) * index.x)))
			return (NULL);
		x = -1;
		while (++x < index.x)
		{
			if (comp[i] == '\n')
				abc[x] = 0;
			else
				abc[x] = (comp[i++] == '0') ? 0 : 1;
		}
		i++;
		ord[y] = abc;
	}
	return (ord);
}

static t_vec2	info_datamap(char *comp)
{
	int		len;
	int		idx;
	t_vec2	i;

	idx = 0;
	i = 0;
	while (comp[idx] != '\0')
	{
		len = 0;
		while (comp[idx] != '\n' && comp[idx] != '\0')
		{
			len++;
			idx++;
		}
		if (i.x < len)
			i.x = len;
		if (comp[idx] != '\0')
			idx++;
		i.y++;
	}
	return (i);
}

static char		*get_fd(const int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;
	char	*result;

	ret = 1;
	tmp = NULL;
	result = NULL;
	if (fd < 0)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = result;
		result = (result == NULL) ? ft_strdup(buf) : ft_strjoin(result, buf);
		free_secure(tmp);
		tmp = NULL;
	}
	return (result);
}

int				map_int(t_env *e, int fd)
{
	char	*line;
	char	*comp;
	t_vec2	i;

	line = NULL;
	if ((comp = get_fd(fd)) == NULL)
		wolf3d_error(e, 1 ^ (1 << 16), "pb fd");
	i = info_datamap(comp);
	e->map->size_x = i.x;
	e->map->size_y = i.y;
	e->map->width_screen = i.y * BLOCKS;
	e->map->height_screen = i.x * BLOCKS;
	e->map->data = compil_map(i, comp, 0);
	free_secure(comp);
	if (e->map->data == NULL)
		wolf3d_error(e, 1 ^ (1 << 16), "can't parse");
	print_map(e->map->data, i);
	return (SUCCESS);
}
