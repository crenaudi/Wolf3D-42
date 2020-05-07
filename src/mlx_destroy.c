/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 00:50:53 by padelord          #+#    #+#             */
/*   Updated: 2020/05/02 00:53:18 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int		mlx_destroy(t_xvar *mlx)
{
	if (mlx && mlx->display)
	{
		XFlush(mlx->display);
		XCloseDisplay(mlx->display);
		free(mlx);
		return (1);
	}
	return (0);
}
