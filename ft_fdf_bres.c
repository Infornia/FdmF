/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:23:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/28 19:06:05 by mwilk            ###   ########.fr       */
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
					(x - p1.x)) / (p2.x - p1.x), BLACK);
		x++;
	}
}

void	check_case(t_data *e)
{
	t_point	p1;
	t_point	p2;

	p1.x = 100;
	p1.y = 100;
	p2.x = X_WIN - 100;
	p2.y = Y_WIN - 100;
	if (p1.x < p2.x && p1.y < p2.y)
		draw_case1(e, p1, p2);
}
