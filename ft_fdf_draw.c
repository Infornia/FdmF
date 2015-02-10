/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:49:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/10 18:02:19 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_data *d)
{
	int	i;
	int	j;
	j = 0;
	if (d->projection_type == PARA)
		calc_para(d, &(d->map->data[0][0]));
	if (d->projection_type == ISO)
		calc_iso(d, &(d->map->data[0][0]));
	while (j < d->map->map_h)
	{
		i = 0;
		while (i < d->map->map_w)
		{
			if (i < d->map->map_w - 1)
				draw_line(d, d->map->data[j][i], &(d->map->data[j][i + 1]));
			if (j < d->map->map_h - 1)
				draw_line(d, d->map->data[j][i], &(d->map->data[j + 1][i]));
			++i;
		}
		++j;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
}

void	draw_rainbow(t_data *e, int size, void *mlx, void *win, int draw)
{
	static int	x;
	static int	y;
	double		d;
    
	d = -X_WIN * 1.85;
	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		while (y < Y_WIN)
		{
			if (draw == PUT)
				mlx_pixel_put(mlx, win, x, y, get_color(d));
			else
				color_pixel(e, get_color(d), x, y, size);
			++y;
			d += 1/(X_WIN * Y_WIN * 0.166);
		}
	++x;
	}
}

int		get_color(double t)
{
	return(RGB(
	127.5 * (cos(t) + 1),
	127.5 * (sin(t) + 1),
	127.5 * (1 - cos(t))
	));
}

void	draw_white(t_data *e, int size, void *mlx, void *win, int draw)
{
	int	x;
	int	y;
    
	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		while (y < Y_WIN)
		{
			if (draw == PUT)
				mlx_pixel_put(mlx, win, x, y, get_color(0xFFFFFF));
			else
				color_pixel(e, WHITE, x, y, size);
			++y;
		}
	++x;
	}
}
