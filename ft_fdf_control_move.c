/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 16:25:27 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/03 20:17:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_left(t_data *d)
{
	d->move_lr -= 50;
	erase_img(d);
}

void	move_right(t_data *d)
{
	d->move_lr += 50;
	erase_img(d);
}

void	move_up(t_data *d)
{
	d->move_ud -= 50;
	erase_img(d);
}

void	move_down(t_data *d)
{
	d->move_ud += 50;
	erase_img(d);
}
