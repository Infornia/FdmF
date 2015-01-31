/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:23:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/31 21:53:50 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_case1(t_data *e, t_point p1, t_point p2)
{
	int		x;

	x = p1.x;
	while (x <= p2.x)
	{
		mlx_pixel_put(e->mlx, e->win, x, p1.y + ((p2.y - p1.y) *
					(x - p1.x)) / (p2.x - p1.x), WHITE);
		x++;
	}
}

void	draw_case2(t_data *e, t_point p1, t_point p2)
{
	int		y;

	y = p1.y;
	while (y <= p2.y)
	{
		mlx_pixel_put(e->mlx, e->win, p1.x + ((p2.x - p1.x) *
					(y - p1.y)) / (p2.y - p1.y), y, WHITE);
		y++;
	}
}

void	check_case(t_data *e, t_point p1, t_point p2)
{
	int		dx;
	int		dy;

	//p1.x = 1200;
	//p2.y = 100;
	//p2.x = 100;
	//p1.y = 600;
	dx *= (dx = p2.x - p1.x) < 0 ? -1 : 1;
	dy *= (dy = p2.y - p1.y) < 0 ? -1 : 1;
	if (dx >= dy)
	{
		if (p1.x <= p2.x)
			draw_case1(e, p1, p2);
		else if (p1.x >= p2.x)
			draw_case1(e, p2, p1);
	}
	else if (dy >= dx)
	{
		if (p1.y >= p2.y)
			draw_case2(e, p2, p1);
		else if (p1.y <= p2.y)
			draw_case2(e, p1, p2);
	}
}
