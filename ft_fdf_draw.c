/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:49:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/15 23:13:51 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_data *e, int x_win, int y_win)
{
	static int	x;
	static int	y;
	double		d;
	static int	b;
    
	d = -2000;
	b = 0;
	x = 0;
	while (x < x_win)
	{
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, color(d));
			y++;
			d += 0.0000025;
		}
	x++;
	b++;
	/*	if (b == 140)
		{
			b = 0;
			d = d << 1;
			if (d > 0xFFFFFF)
				d = 0x969600;
		}*/
	}
}

int		color(double t)
{
	return(RGB(
	127.5 * (cos(t) + 1),
	127.5 * (sin(t) + 1),
	127.5 * (1 - cos(t))
	));
}
