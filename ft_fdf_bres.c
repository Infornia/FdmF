/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:23:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/31 16:17:20 by mwilk            ###   ########.fr       */
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
	int		sub_x;
	int		sub_y;

	x = p1.x;
	sub_x = p2.x - p1.x;
	sub_y = p2.y - p1.y;
	if (sub_x)
	{
		while (x <= p2.x)
		{
			color_pixel(d, color_selec(d, p1, p2), x, p1.y + (sub_y *
					(x - p1.x)) / sub_x);
			++x;
		}
	}
}

void	draw_case2(t_data *d, t_point p1, t_point p2)
{
	int		y;
	int		sub_x;
	int		sub_y;

	y = p1.y;
	sub_x = p2.x - p1.x;
	sub_y = p2.y - p1.y;
	if (sub_y)
	{
		while (y <= p2.y)
		{
			color_pixel(d, color_selec(d, p1, p2), p1.x + (sub_x *
					(y - p1.y)) / sub_y, y);
			++y;
		}
	}
}
