/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:27:43 by padelord          #+#    #+#             */
/*   Updated: 2020/05/09 23:31:20 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

int		check_param(char *path, char *ext)
{
	t_u32	sp;
	t_u32	se;

	if ((sp = ft_strlen(path)) < (se = ft_strlen(ext)))
		return (0);
	return (!(ft_strcmp(path + sp - se, ext)));
}
