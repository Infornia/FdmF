/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:49:17 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/17 18:22:56 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_data *e, int x_win, int y_win)
{
	static int	x;
	static int	y;
	static int	d;
	static int	b;
    
	d = 0;
	b = 0;
	x = 0;
	while (x < x_win)
	{
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, d);
			y++;
		}
	x++;
	b++;
	d += 1;
		if (b == 140)
		{
			b = 0;
			d = d << 1;
			if (d > 0xFFFFFF)
				d = 0x969600;
		}
	}
}
