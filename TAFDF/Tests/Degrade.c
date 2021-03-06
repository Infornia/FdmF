/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Degrade.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/17 18:14:05 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

void	draw(t_struc e, int x_win, int y_win)
{
	static int	x;
	static int	y;
	static int	d;
	static int	b;

	d = 0;
	b = 0;
	x = 0;
	while (x < x_win)
	{
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, d);
			y++;
		}
		x++;
		b++;
		d += 1;
		if (b == 140)
		{
			b = 0;
			d = d << 1;
			if (d > 0xFFFFFF)
				d = 0x969600;
		}
	}
	d += 0x001001;
	/*while (x < x_win && d < 0x00FF00)
	{
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, d);
			y++;
		}
		x++;
		d += 0x000100;
	}
	while (x < x_win && d < 0x00FFFF)
	{
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, d);
			y++;
		}
		x++;
		d += 0x000001;
	}
	d += 0x000101;
	while (x < x_win && d < 0xFF0000)
	{
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, d);
			y++;
		}
		x++;
		d += 0x010000;
	}
	while (x < x_win && d < 0xFF00FF)
	{
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, d);
			y++;
		}
		x++;
		d += 0x000001;
	}
	while (x < x_win && d < 0xFFFFFF)
	{
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, d);
			y++;
		}
		x++;
		d += 0x000100;
	}
	d += 0x010000;
	while (x < x_win * 2/3)
	{
		d = RED;
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, d);
			y++;
		}
		x++;
	}
	while (x < x_win)
	{
		d = PINK;
		y = 0;
		while (y < y_win)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, d);
			y++;
		}
		x++;
	}*/
}

int		expose_hook(t_struc *e)
{
	draw(*e, e->x_win, e->x_win/2);
	return(0);
}

int		key_hook(int keycode, t_struc *e)
{
	printf("Key %d\n", keycode);
	if (keycode >= 97 && keycode <= 122)
		return (0);
	if (keycode == 65307)
		exit(0);
	printf("%d", WHITE);
	return (0);
}

int		main(int ac, char **av)
{
	t_struc	e;
	int		i;

	i = 0;
	e.x_win = 2500;
	e.mlx = mlx_init();
	e.win = mlx_new_window (e.mlx, e.x_win, e.x_win/2, "Degrade");
	e.img = mlx_new_image (e.mlx, e.x_win, e.x_win/2);
	mlx_expose_hook(e.win, expose_hook, &e);
    mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
