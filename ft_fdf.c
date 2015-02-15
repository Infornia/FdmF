/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/15 22:53:13 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_init(t_data *d, char *file)
{
	int		i;

	i = 0;
	d->file_name = file;
	d->projection_type = ISO;
	d->draw_type = IMG;
	d->color_mode = 0;
	d->lr = X_WIN * 2/5;
	d->ud = 200 + Y_WIN / 1000;
	d->mlx = mlx_init();
	d->win = mlx_new_window (d->mlx, X_WIN, Y_WIN, "FdF");
	d->img = mlx_new_image(d->mlx, X_WIN, Y_WIN);
	d->data_img = mlx_get_data_addr(d->img, &(d->bpp), &(d->size), &(d->endian));
	get_map(d);
	d->zoom = 1 + (X_WIN / d->map->map_w / 8) + (Y_WIN / d->map->map_h / 5);
	d->peaks = d->map->z_max / Y_WIN;
	if (d->win)
	{
		//mlx_key_hook(d->win, key_hook, d);
		mlx_hook(d->win, 3, 3, key_hook, d);
		mlx_mouse_hook(d->win, mouse_hook, d);
		mlx_expose_hook(d->win, expose_hook, d);
		mlx_loop(d->mlx);
	}
}

void		ft_fdf_exit(t_data *d)
{

	exit(0);
}

int		expose_hook(t_data *d)
{
	if (d->color_mode == 1)
		draw_rainbow(d, d->size, d->mlx, d->win, d->draw_type);
	else if (d->color_mode == 3)
		draw_white(d, d->size, d->mlx, d->win, d->draw_type);
	print_map(d);
	return(0);
}

int		key_hook(int keycode, t_data *d)
{
	printf("Key %d\n", keycode);
	if (keycode == 65361)
		move_left(d);
	else if (keycode == 65363)
		move_right(d);
	else if (keycode == 65362)
		move_up(d);
	else if (keycode == 65364)
		move_down(d);
	else if (keycode == 61)
		more_zoom(d);
	else if (keycode == 45)
		less_zoom(d);
	else if (keycode == 93)
		more_peak(d);
	else if (keycode == 91)
		less_peak(d);
	else if (keycode == 49)
		d->color_mode = 1;
	else if (keycode == 50)
		d->color_mode = 2;
	else if (keycode == 51)
	{
		if (d->color_mode != 3)
			d->color_mode = 3;
		else
			d->color_mode = 10;
	}
	else if (keycode == 52)
		d->color_mode = 4;
	else if (keycode == 112)
		d->projection_type = PARA;
	else if (keycode == 105)
		d->projection_type = ISO;
	else if (keycode == 65307)
		ft_fdf_exit(d);
	else
		return (0);
	erase_img(d);
	return (0);
}

int		mouse_hook(int	button, int x, int y, t_data *d)
{
	//printf("Mouse Button: %d\n", button);
	if (button == 1 && x > (X_WIN - 25) && y < 25)
		ft_fdf_exit(d);
	//printf("Mouse x: %d\n", x);
	//printf("Mouse y: %d\n", y);
	return (0);
}
