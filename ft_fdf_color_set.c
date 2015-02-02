/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_color_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/02 15:56:36 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_pixel(t_data *e, int color, int x, int y)
{
	int	i;
	
	i = x * 4 + y * e->size;
	e->data_img[i] = color % 256;
	color /= 256;
	e->data_img[i + 1] = color % 256;
	color /= 256;
	e->data_img[i + 2] = color % 256;
}
