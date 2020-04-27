/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:48:05 by padelord          #+#    #+#             */
/*   Updated: 2020/04/27 16:02:39 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/time.h>
#include "../includes/wolf.h"
#define FPS 16666

typedef struct		s_fps
{
	struct timeval	prev;
	struct timeval	cur;
	int				frame;
}					t_fps;

void				fps(void)
{
	static t_fps	data;
	static int		frame = -1;
	t_u64			duration;

	if (frame == -1)
	{
		frame = 0;
		gettimeofday(&data.cur, 0);
	}
	data.prev = data.cur;
	gettimeofday(&(data.cur), 0);
	duration = 0;
	if (data.cur.tv_sec != data.prev.tv_sec)
	{
		printf("%d frames\n", frame);
		frame = 0;
		duration = 1000000;
	}
	duration += (data.cur.tv_usec - data.prev.tv_usec);
	if (duration < FPS)
		usleep(FPS - duration);
	frame++;
}
