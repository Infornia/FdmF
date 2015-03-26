/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:39:44 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/26 18:38:58 by mwilk            ###   ########.fr       */
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
	else if (d->projection_type == ISO)
	{
		p->x = x - y + d->lr;
		p->y = -z + x + y + d->ud;
	}
}

void	erase_img(t_data *d)
{
	d->img = mlx_new_image(d->mlx, X_WIN, Y_WIN);
	d->data_img = mlx_get_data_addr(d->img, &(d->color), &(d->size), &(d->endian));
	expose_hook(d);
}
