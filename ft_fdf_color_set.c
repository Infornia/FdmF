/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_color_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/26 13:23:44 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define COL_R(i) (i >> 16) & 0x000000ff
# define COL_G(i) (i >> 8) & 0x000000ff
# define COL_B(i) i & 0x000000ff

void	color_pixel(t_data *e, int color, int x, int y, int size)
{
	int	i;
	
	if (x > 0 && x < X_WIN && y > 0 && y < Y_WIN)
	{
		i = x * 4 + y * size;
		e->data_img[i] = COL_B(color);
		e->data_img[i + 1] = COL_G(color);
		e->data_img[i + 2] = COL_R(color);
	}
}

int		color_selec(t_data *d, t_point p1, t_point p2)
{
	if (d->color_mode == 3)
		return (BLACK);
	if (d->color_mode == 4)
	{
		if (p1.d3_z == p2.d3_z)
		{
			if (p1.d3_z == 0)
				return (QUOISE);
			else
				return (PINK);
		}
		else
			return (BLACK);
	}
	return (WHITE);
}

void	color_hook(int keycode, t_data *d)
{
	if (keycode == 18)
	{
		d->rainbow++;
		if (d->rainbow > X_WIN)
			d->rainbow = 0;
		d->color_mode = 1;
	}
	if (keycode == 19)
	{
		d->rainbow++;
		if (d->rainbow > X_WIN)
			d->rainbow = 0;
		d->color_mode = 5;
	}
	else if (keycode == 23)
		d->color_mode = 2;
	else if (keycode == 20)
	{
		if (d->color_mode != 3)
			d->color_mode = 3;
		else
			d->color_mode = 10;
	}
	else if (keycode == 21)
		d->color_mode = 4;
}
