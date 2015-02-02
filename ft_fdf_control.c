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

void	move_left(t_data *d)
{
	d->move_lr += 10;	
}

void	move_right(t_data *d)
{
	d->move_lr -= 10;	
}

void	move_up(t_data *d)
{
	d->move_ud += 10;
}

void	move_down(t_data *d)
{
	d->move_ud -= 10;
}
