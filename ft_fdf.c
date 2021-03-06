/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/31 15:36:38 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_init(t_data *d, char *file)
{
	d->file_name = file;
	d->projection_type = ISO;
	d->draw_type = IMG;
	d->color_mode = 0;
	d->lr = X_WIN * 2 / 5;
	d->ud = 200 + Y_WIN / 1000;
	d->mlx = mlx_init();
	d->win = mlx_new_window (d->mlx, X_WIN, Y_WIN, "FdF");
	d->img = mlx_new_image(d->mlx, X_WIN, Y_WIN);
	d->data_img = mlx_get_data_addr
		(d->img, &(d->bpp), &(d->size), &(d->endian));
	get_map(d);
	init_events(d);
	d->zoom =
		(X_WIN / (d->map->map_w + 1) / 8) + (Y_WIN / (d->map->map_h + 1) / 6);
	d->peaks = d->map->z_max / Y_WIN;
	if (d->win)
	{
		mlx_hook(d->win, 2, 4, key_hook, d);
		mlx_mouse_hook(d->win, mouse_hook, d);
		mlx_expose_hook(d->win, expose_hook, d);
		mlx_loop(d->mlx);
	}
}

void	ft_fdf_exit(t_data *d)
{
	(void)d;
	exit(0);
}

int		expose_hook(t_data *d)
{
	if (d->color_mode == 1)
		draw_rainbow(d);
	else if (d->color_mode == 3)
		draw_white(d);
	else if (d->color_mode == 5)
		draw_luminotherapy(d);
	print_map(d);
	return (0);
}

int		key_hook(int keycode, t_data *d)
{
	int	i;

	i = 0;
	if (keycode >= 18 && keycode <= 23)
		color_hook(keycode, d);
	else if (keycode == 35)
		d->projection_type = PARA;
	else if (keycode == 34)
		d->projection_type = ISO;
	while (i < TKEY)
	{
		if (d->key_event[i].key_code == keycode)
			d->key_event[i].event(d);
		i++;
	}
	erase_img(d);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_data *d)
{
	if (button == 1 && x > (X_WIN - 25) && y < 25)
		ft_fdf_exit(d);
	return (0);
}
