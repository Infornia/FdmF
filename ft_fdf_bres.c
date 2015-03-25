/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:23:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 19:07:00 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *d, t_point p1, t_point *p2)
{
	int		dx;
	int		dy;

	calc(d, p2);
	dx = abs(p2->x - p1.x);
	dy = abs(p2->y - p1.y);
	if (dx >= dy)
	{
		if (p1.x <= p2->x)
			draw_case1(d, p1, *p2);
		else if (p1.x >= p2->x)
			draw_case1(d, *p2, p1);
	}
	else if (dy >= dx)
	{
		if (p1.y >= p2->y)
			draw_case2(d, *p2, p1);
		else if (p1.y <= p2->y)
			draw_case2(d, p1, *p2);
	}
}

void	draw_case1(t_data *d, t_point p1, t_point p2)
{
	int		x;

	x = p1.x;
	if (d->draw_type == PUT)
	{
		while (x <= p2.x)
		{
			mlx_pixel_put(d->mlx, d->win, x, p1.y + ((p2.y - p1.y) *
					(x - p1.x)) / (p2.x - p1.x), color_selec(d, p1, p2));
			++x;
		}
	}
	else if (d->draw_type == IMG)
	{
		while (x <= p2.x)
		{
			color_pixel(d, color_selec(d, p1, p2), x, p1.y + ((p2.y - p1.y) *
					(x - p1.x)) / (p2.x - p1.x), d->size);
			++x;
		}
	}
}

void	draw_case2(t_data *d, t_point p1, t_point p2)
{
	int		y;

	y = p1.y;
	if (d->draw_type == PUT)
	{
		while (y <= p2.y)
		{
			mlx_pixel_put(d->mlx, d->win, p1.x + ((p2.x - p1.x) *
					(y - p1.y)) / (p2.y - p1.y), y, color_selec(d, p1, p2));
			++y;
		}
	}
	else if (d->draw_type == IMG)
	{
		while (y <= p2.y)
		{
			color_pixel(d, color_selec(d, p1, p2), p1.x + ((p2.x - p1.x) *
					(y - p1.y)) / (p2.y - p1.y), y, d->size);
			++y;
		}
	}
}
