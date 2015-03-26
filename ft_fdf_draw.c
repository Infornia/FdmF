/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:49:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/26 18:39:02 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_data *d)
{
	int	i;
	int	j;
	j = 0;
	calc(d, &(d->map->data[0][0]));
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
	mlx_do_sync(d->mlx);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
}

int		get_color(float t)
{
	return (RGB(
	127.5 * (cos(t) + 1),
	127.5 * (sin(t) + 1),
	127.5 * (1 - cos(t))
		));
}

void	draw_rainbow(t_data *e, int size)
{
	int			x;
	int			y;
	float		d;
	int			color;	

	d = e->rainbow * 0.5;
	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		d += 0.0025;
		color = get_color(d);
		while (y < Y_WIN)
		{
			color_pixel(e, color, x, y, size);
			++y;
		}
	++x;
	}
}

void	draw_luminotherapy(t_data *e, int size)
{
	int			x;
	int			y;
	float		d;
	int			color;	

	d = e->rainbow * 0.09;
	x = 0;
	color = get_color(d);
	while (x < X_WIN)
	{
		y = 0;
		while (y < Y_WIN)
		{
			color_pixel(e, color, x, y, size);
			++y;
		}
	++x;
	}
}

void	draw_white(t_data *e, int size)
{
	int	x;
	int	y;
    
	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		while (y < Y_WIN)
		{
			color_pixel(e, WHITE, x, y, size);
			++y;
		}
	++x;
	}
}

/*void	draw_board(t_data *d)
{
	int	x;
	int	y;
    
	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		if (x < X_WIN * 3/)
		while (y < 200)
		{
			color_pixel(d, GRAY, x, y, size);
			++y;
		}
	++x;
	}
}
*/
