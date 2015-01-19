/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:49:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/19 18:13:46 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_data *e, int x_win, int y_win)
{
	static int	x;
	static int	y;
	double		d;
	static int	b;
    
	d = -x_win * 1.85;
	b = 0;
	x = 0;
	while (x < x_win)
	{
		y = 0;
		while (y < y_win)
		{
			e->color = color(d);
			mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			//ft_memcpy(&e->data[(x * 4)], (void *)e->color, (size_t)(sizeof(int)));
			y++;
			//d += 0.0000025;
			d += 1/(x_win * y_win * 0.166);
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
