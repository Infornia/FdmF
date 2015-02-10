/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:39:44 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/10 18:44:16 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_para(t_data *d, t_point *p)
{
		p->x = p->d3_x * d->zoom + d->peaks * p->d3_z + X_WIN * 0.5 + d->lr;
		p->y = p->d3_y * d->zoom - d->peaks * 0.5 * p->d3_z + Y_WIN * 0.3 + d->ud;
}

void	calc_iso(t_data *d, t_point *p)
{
		p->x = (p->d3_x - p->d3_y) * d->zoom + X_WIN * 0.5 + d->lr;
		p->y = p->d3_z * -(d->peaks) + (p->d3_x + p->d3_y) * d->zoom + Y_WIN * 0.3 + d->ud;
}

void	erase_img(t_data *d)
{
	d->img = mlx_new_image(d->mlx, X_WIN, Y_WIN);
	d->data_img = mlx_get_data_addr(d->img, &(d->color), &(d->size), &(d->endian));
	ft_putnbr(d->color);
	expose_hook(d);
}
