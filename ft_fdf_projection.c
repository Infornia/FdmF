/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:39:44 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/26 15:41:49 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc(t_data *d, t_point *p)
{
	int	x;
	int	y;
	int	z;

	x = p->d3_x * d->zoom;
	y = p->d3_y * d->zoom;
	z = p->d3_z * d->peaks;
	if (d->projection_type == PARA)
	{
		p->x = x + z + d->lr;
		p->y = y - 0.5 * z + d->ud;
	}
	if (d->projection_type == ISO)
	{
		p->x = x - y + d->lr;
		p->y = -z + x + y + d->ud;
	}
	rotation2(p);
}

void	rotation2(t_point *p)
{
	int	px_tmp;

	px_tmp = p->x;
	p->x = (float)(p->x) * cos(0.3) + (float)(p->x) + sin(0.3) + 0.5;
	p->y = (float)(-px_tmp) * sin(0.3) + (float)(p->y) + cos(0.3) + 0.5;	
}

void	rotation(t_data *d)
{
	int	i;
	int	j;
	int	px_tmp;
	t_point	*p;

	j = 0;
	while (j < d->map->map_h)
	{
		i = 0;
		while (i < d->map->map_w)
		{
			p = &(d->map->data[j][i]);
			px_tmp = p->x;
			p->x = (float)(p->x) * cos(0.3) + (float)(p->x) + sin(0.3) + 0.5;
			p->y = (float)(-px_tmp) * sin(0.3) + (float)(p->y) + cos(0.3) + 0.5;
			++i;
		}
		++j;
	}
}

void	erase_img(t_data *d)
{
	d->img = mlx_new_image(d->mlx, X_WIN, Y_WIN);
	d->data_img = mlx_get_data_addr(d->img, &(d->color), &(d->size), &(d->endian));
	expose_hook(d);
}
