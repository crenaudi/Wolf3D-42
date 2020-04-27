/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddeg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:15:48 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 15:16:42 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libgfx_includes/gfx.h"

float	deg2rad(float d)
{
	float	r;

	r = (d / 180.0f) * M_PI;
	return (r);
}

float	rad2deg(float r)
{
	float	d;

	d = (r / M_PI) * 180.0f;
	return (d);
}
