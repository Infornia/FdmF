/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:23:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/02 17:41:55 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_case1(t_data *e, t_point p1, t_point p2)
{
	int		x;

	x = p1.x;
	if (e->draw_type == PUT)
	{
		while (x <= p2.x)
		{
			mlx_pixel_put(e->mlx, e->win, x, p1.y + ((p2.y - p1.y) *
						(x - p1.x)) / (p2.x - p1.x), BLACK);
			x++;
		}
	}
	else if (e->draw_type == IMG)
	{
		while (x <= p2.x)
		{
			color_pixel(e, BLACK, x, p1.y + ((p2.y - p1.y) *
						(x - p1.x)) / (p2.x - p1.x));
			x++;
		}
	}
}

void	draw_case2(t_data *e, t_point p1, t_point p2)
{
	int		y;

	y = p1.y;
	if (e->draw_type == PUT)
	{
		while (y <= p2.y)
		{
			mlx_pixel_put(e->mlx, e->win, p1.x + ((p2.x - p1.x) *
						(y - p1.y)) / (p2.y - p1.y), y, BLACK);
			y++;
		}
	}
	else if (e->draw_type == IMG)
	{
		while (y <= p2.y)
		{
			color_pixel(e, BLACK, p1.x + ((p2.x - p1.x) *
						(y - p1.y)) / (p2.y - p1.y), y);
			y++;
		}
	}
}

void	draw_line(t_data *d, t_point p1, t_point p2)
{
	int		dx;
	int		dy;

	//calc_control(&p1);
	//calc_control(&p2);
	calc_proj(&p1, d->projection_type);
	calc_proj(&p2, d->projection_type);
	dx *= (dx = p2.x - p1.x) < 0 ? -1 : 1;
	dy *= (dy = p2.y - p1.y) < 0 ? -1 : 1;
	if (dx >= dy)
	{
		if (p1.x <= p2.x)
			draw_case1(d, p1, p2);
		else if (p1.x >= p2.x)
			draw_case1(d, p2, p1);
	}
	else if (dy >= dx)
	{
		if (p1.y >= p2.y)
			draw_case2(d, p2, p1);
		else if (p1.y <= p2.y)
			draw_case2(d, p1, p2);
	}
}
