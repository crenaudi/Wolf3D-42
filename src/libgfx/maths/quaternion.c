/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:15:48 by crenaudi          #+#    #+#             */
/*   Updated: 2020/04/27 14:50:21 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libgfx_includes/gfx.h"

float	norm_quaternion_norm(t_q *q)
{
	if (q == NULL)
		return (0.0);
	return (ft_sqrt(q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w));
}

void	quaternion_neg(t_q *r, t_q *q)
{
	if (q == NULL || r == NULL)
		return ;
	r->x = -q->x;
	r->y = -q->y;
	r->z = -q->z;
	r->w = -q->w;
}

t_q		*add_real_num(float r, t_q *q)
{
	q->x = q->x + r;
	return (q);
}

bool	quaternion_equal(t_q *q1, t_q *q2)
{
	if (q1->x != q2->x || q1->y != q2->y || q1->z != q2->z || q1->w != q2->w)
		return (false);
	return (true);
}
