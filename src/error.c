/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:45:47 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 14:57:28 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	wolf3d_error(t_env *e, unsigned int err, char *line)
{
	char			*s[4] = {"Error malloc : ",
							"Invalid map : ",
							"Error texture : ",
							"Error base_pal : "};
	unsigned int	close;

	close = err >> 16;
	ft_putstr(s[err & (0 << 16)]);
	if (line != NULL)
	ft_putendl(line);
	if (close == 1)
	clean(e);
}
