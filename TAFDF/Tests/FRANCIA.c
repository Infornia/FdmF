/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FRANCIA.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/15 16:51:00 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>

#define RED 0xFF0000
#define BLUE 0x0000FF
#define GREEN 0xFF0000
#define WHITE 0xFFFFFF
#define PINK 0xFF00FF

typedef	struct	s_struc
{
	void	*mlx;
	void	*win;
	int		x_win;
}			t_struc;

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
		mlx_string_put(e.mlx, e.win, x++, y++, PINK, "_________________________");
	}
}

int		expose(t_struc *e)
{
	draw(*e, e->x_win, e->x_win/2);
	draw_str(*e, e->x_win, e->x_win/2);
	return(0);
}

int		main(int ac, char **av)
{
	t_struc	e;

	e.x_win = 2200;
	e.mlx = mlx_init();
	e.win = mlx_new_window (e.mlx, e.x_win, e.x_win/2, "MISS FRANCE 2K15");
	sleep(2);
	mlx_expose_hook(e.win, expose, &e);
	usleep(500);
	mlx_loop(e.mlx);
	return (0);
}
