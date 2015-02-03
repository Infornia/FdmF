/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:39:44 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/02 18:09:20 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_proj(t_point *p, int proj)
{
	if (proj == PARA)
	{
		p->x = p->d3_x + 0.7 * p->d3_z + X_WIN * 0.5;
		p->y = p->d3_y + -1 * 0.35 * p->d3_z + Y_WIN * 0.3;
	}
	if (proj == ISO)
	{
		p->x = p->d3_x - p->d3_y + X_WIN * 0.5;
		p->y = p->d3_z * -1 + p->d3_x * 0.5 + p->d3_y * 0.5 + Y_WIN * 0.3;
	}
}

void	calc_control(t_point *p)
{
	
}

void	erase_img(t_data *d)
{
	ft_bzero(d->data_img, Y_WIN * X_WIN * 4);
	expose_hook(d);
}
