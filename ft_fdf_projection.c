/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:39:44 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/31 21:53:52 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_proj(t_point *p, int d3_x, int d3_y, int d3_z, int proj)
{
	if (proj == PARA)
	{
		p->x = d3_x + d3_z + X_WIN * 0.5;
		p->y = d3_y + 0.5 * d3_z + Y_WIN * 0.3;
	}
	if (proj == ISO)
	{
		p->x = d3_x - d3_y + X_WIN * 0.5;
		p->y = -d3_z + d3_x * 0.5 + d3_y * 0.5 + Y_WIN * 0.3;
	}
}

void	draw_line1(t_data *d, int x, int y, int z1, int z2)
{
	t_point p1;
	t_point	p2;

	printf("DANS DRAW_LINE -> le x: %i, y: %i, z1: %i z2: %i, proj: %i\n", x, y, z1, z2, d->projection_type);
	p1.x = 0;
	p1.y = 0;
	p2.x = 0;
	p2.y = 0;
	x *= 20;
	y *= 20;
	printf("-> x1 %i, x2 %i, y1 %i, y2 %i\n", p1.x, p1.y, p2.x, p2.y);
	calc_proj(&p1, x, y, z1, d->projection_type);
	calc_proj(&p2, x + 20, y, z2, d->projection_type);
	check_case(d, p1, p2);
}

void	draw_line2(t_data *d, int x, int y, int z1, int z2)
{
	t_point p1;
	t_point	p2;

	p1.x = 0;
	p1.y = 0;
	p2.x = 0;
	p2.y = 0;
	x *= 20;
	y *= 20;
	calc_proj(&p1, x, y, z1, d->projection_type);
	calc_proj(&p2, x, y + 20, z2, d->projection_type);
	check_case(d, p1, p2);
}
