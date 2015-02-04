/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:39:44 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/04 17:55:09 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_para(t_point *p, int lr, int ud, double zoom, double peaks)
{
		p->x = p->d3_x * zoom + peaks * p->d3_z + X_WIN * 0.5 + lr;
		p->y = p->d3_y * zoom + -peaks / 2 * p->d3_z + Y_WIN * 0.3 + ud;
}

void	calc_iso(t_point *p, int lr, int ud, double zoom, double peaks)
{
		p->x = (p->d3_x - p->d3_y) * zoom + X_WIN * 0.5 + lr;
		p->y = p->d3_z * -peaks + (p->d3_x + p->d3_y) * zoom + Y_WIN * 0.3 + ud;
}

void	erase_img(t_data *d)
{
	ft_bzero(d->data_img, Y_WIN * X_WIN * 4);
	expose_hook(d);
}
