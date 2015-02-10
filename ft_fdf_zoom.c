/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:07:41 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/10 18:55:01 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	more_zoom(t_data *d)
{
	d->zoom += d->map->map_w * 0.001;
	erase_img(d);
}

void	less_zoom(t_data *d)
{
	d->zoom -= d->map->map_w * 0.001;
	erase_img(d);
}

void	more_peak(t_data *d)
{
	d->peaks += d->map->z_max * 0.01;
	erase_img(d);
}

void	less_peak(t_data *d)
{
	d->peaks -= d->map->z_max * 0.01;
	erase_img(d);
}
