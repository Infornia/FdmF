/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 16:25:27 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/02 17:16:59 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// nom ft_fdf_check_points.c
int		check_x(t_data *d)
{
	if ((d->move_lr + x) > 0) || ((d->move_lr + x) < X_WIN)
		return (1);
	return (0);
}

int		check_y(t_data *d)
{
	if ((d->move_ud + y) > 0) || ((d->move_ud + y) < Y_WIN)
		return (1);
	return (0);
}
