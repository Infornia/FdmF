/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/11 21:17:40 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int		color_set(int keycode, t_struc *e)
{
	if (keycode == 114)
		e->color = RED;
	if (keycode == 103)
		e->color = GREEN;
	if (keycode == 98)
		e->color = BLUE;
	if (keycode == 119)
		e->color = WHITE;
	if (keycode == 108)
		e->color = BLACK;
	if (keycode == 112)
		e->color = PINK;
	printf("%lu",e->color);
	return (0);
}
