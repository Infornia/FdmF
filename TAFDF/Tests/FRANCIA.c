/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FRANCIA.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/15 20:31:57 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include "Fdf.h"

void	draw(t_struc e, int x_win, int y_win)
{
	int	x;
	int	y;

	x = 0;
	while (x < x_win / 3)
	{
		y = 0;
		while (y < y_win)
		{
			usleep(5);
			mlx_pixel_put(e.mlx, e.win, x, y, BLUE);
			y++;
		}
		x++;
	}
	while (x < x_win * 2/3)
	{
		y = 0;
		while (y < y_win)
		{
			usleep(5);
			mlx_pixel_put(e.mlx, e.win, x, y, WHITE);
			y++;
		}
		x++;
	}
	while (x < x_win)
	{
		y = 0;
		while (y < y_win)
		{
			usleep(5);
			mlx_pixel_put(e.mlx, e.win, x, y, RED);
			y++;
		}
		x++;
	}
}

void	draw_str(t_struc e, int x_win, int y_win)
{
	int	x;
	int	y;
	
	x = x_win - (x_win * 3/4);
	y = 0;
	while (y < y_win && x_win)
	{
		usleep(1000);
		mlx_string_put(e.mlx, e.win, x++, y++, PINK, "_________________________");
	}
}

int		expose_hook(t_struc *e)
{
	draw(*e, e->x_win, e->x_win/2);
	draw_str(*e, e->x_win, e->x_win/2);
	return(0);
}

int		key_hook(int keycode, t_struc *e)
{
	printf("Key %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	printf("%d", WHITE);
	return (0);
}

int		main(int ac, char **av)
{
	t_struc	e;

	e.x_win = 2200;
	e.mlx = mlx_init();
	e.win = mlx_new_window (e.mlx, e.x_win, e.x_win/2, "MISS FRANCE 2K15");
	e.img = mlx_new_image (e.mlx, e.x_win, e.x_win/2);
    mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
