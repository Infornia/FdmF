/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:23:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/10 18:00:30 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *d, t_point p1, t_point *p2)
{
	int		dx;
	int		dy;

	if (d->projection_type == PARA)
		calc_para(d, p2);
	if (d->projection_type == ISO)
		calc_iso(d, p2);
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

void	draw_case1(t_data *e, t_point p1, t_point p2)
{
	int		x;

	x = p1.x;
	if (e->draw_type == PUT)
	{
		while (x <= p2.x)
		{
			mlx_pixel_put(e->mlx, e->win, x, p1.y + ((p2.y - p1.y) *
					(x - p1.x)) / (p2.x - p1.x), e->color);
			++x;
		}
	}
	else if (e->draw_type == IMG)
	{
		while (x <= p2.x)
		{
			color_pixel(e, e->color, x, p1.y + ((p2.y - p1.y) *
					(x - p1.x)) / (p2.x - p1.x), e->size);
			++x;
		}
	}
}

void	draw_case2(t_data *e, t_point p1, t_point p2)
{
	int		x;
	int		y;

	y = p1.y;
	if (e->draw_type == PUT)
	{
		while (y <= p2.y)
		{
			mlx_pixel_put(e->mlx, e->win, p1.x + ((p2.x - p1.x) *
					(y - p1.y)) / (p2.y - p1.y), y, e->color);
			++y;
		}
	}
	else if (e->draw_type == IMG)
	{
		while (y <= p2.y)
		{
			color_pixel(e, e->color, p1.x + ((p2.x - p1.x) *
					(y - p1.y)) / (p2.y - p1.y), y, e->size);
			++y;
		}
	}
}
