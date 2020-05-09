/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 20:46:08 by padelord          #+#    #+#             */
/*   Updated: 2020/05/09 20:46:09 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx_int.h"

void mlx_destroy(t_xvar *mlx)
{
	XFlush(mlx->display);
	XCloseDisplay(mlx->display);
	free(mlx);
}
