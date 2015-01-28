/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:49:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/28 18:33:45 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_put_img(t_data *e, int color, int x, int y)
{
	int	i;
	
	i = x * 4 + y * e->size;
	e->data_img[i] = color % 256;
	color /= 256;
	e->data_img[i + 1] = color % 256;
	color /= 256;
	e->data_img[i + 2] = color % 256;
}

void	draw(t_data *e, int x_win, int y_win)
{
	static int	x;
	static int	y;
	double		d;
    
	d = -x_win * 1.85;
	x = 0;
	while (x < x_win)
	{
		y = 0;
		while (y < y_win)
		{
			e->color = color(d);
			//mlx_pixel_put(e->mlx, e->win, x, y, e->color);
			mlx_put_img(e, e->color, x, y);
			y++;
			d += 1/(x_win * y_win * 0.166);
		}
	x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		color(double t)
{
	return(RGB(
	127.5 * (cos(t) + 1),
	127.5 * (sin(t) + 1),
	127.5 * (1 - cos(t))
	));
}
/*void	draw_line(t_data *d, t_mesh p1, t_mesh p2)
{
	
}

void	print_map(t_data *d)
{
	int	i;
	int	j;
	while (j < d->map->map_h)
	{
		while (i < d->map->map_w)
		{
			if (i < d->map->x_max - 1)
				draw_line(d, d->map->data[j][i], d->map->data[j][i + 1]);
			if (j < d->map->y_max - 1)
				draw_line(d, d->map->data[j][i], d->map->data[j + 1][i]);
			i++;
		}
		j++;
	}
}*/


