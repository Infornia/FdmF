/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:23:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/30 18:32:35 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_case1(t_data *e, t_point p1, t_point p2)
{
	int		x;

	x = p1.x;
	ft_putendl("Bowdel cas1");
	while (x <= p2.x)
	{
		mlx_pixel_put(e->mlx, e->win, x, p1.y + ((p2.y - p1.y) *
					(x - p1.x)) / (p2.x - p1.x), BLACK);
		x++;
	}
}

void	draw_case2(t_data *e, t_point p1, t_point p2)
{
	int		y;

	y = p1.y;
	ft_putendl("Bowdel cas2");
	ft_putendl("P1");
	ft_putnbr(p1.y);
	ft_putchar('\n');
	ft_putendl("P2");
	ft_putnbr(p2.y);
	ft_putchar('\n');
	while (y <= p2.y)
	{
		mlx_pixel_put(e->mlx, e->win, p1.x + ((p2.x - p1.x) *
					(y - p1.y)) / (p2.y - p1.y), y, BLACK);
		y++;
	}
}

void	check_case(t_data *e)
{
	t_point	p1;
	t_point	p2;
	int		dx;
	int		dy;
	//A traiter: Les points, leur voisinnage
	p1.x = 100;
	p2.y = 200;
	p2.x = 100;
	p1.y = 200;
	dx *= (dx = p2.x - p1.x) < 0 ? -1 : 1;
	dy *= (dy = p2.y - p1.y) < 0 ? -1 : 1;
	//printf("%i\n%i\n", dx, dy);
	if (dx >= dy)
	{
		ft_putendl("if 1 Bowdel");
		if ((p1.x <= p2.x && p1.y >= p2.y) || (p1.x <= p2.x && p1.y <= p2.y))
			draw_case1(e, p1, p2);
		else if ((p1.x >= p2.x && p1.y <= p2.y) ||
				(p1.x >= p2.x && p1.y >= p2.y))
			draw_case1(e, p2, p1);
	}
	else if (dy >= dx)
	{
		ft_putendl("if 2 Bowdel");
		if ((p1.x <= p2.x && p1.y >= p2.y) || (p1.x >= p2.x && p1.y >= p2.y))
		{
			ft_putendl("PREMIER IF");
			draw_case2(e, p2, p1);
		}
		else if ((p1.x >= p2.x && p1.y <= p2.y) ||
				(p1.x <= p2.x && p1.y <= p2.y))
		{
			ft_putendl("DEUXIEME IF");
			draw_case2(e, p1, p2);
		}
	}
}
