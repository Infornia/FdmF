/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:07:41 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/26 13:01:49 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	more_zoom(t_data *d)
{
	d->zoom += 1;
	erase_img(d);
}

void	less_zoom(t_data *d)
{
	if (d->zoom > 1)
		d->zoom -= 1;
	erase_img(d);
}

void	more_peak(t_data *d)
{
	d->peaks += 1;
	erase_img(d);
}

void	less_peak(t_data *d)
{
	d->peaks -= 1;
	erase_img(d);
}
