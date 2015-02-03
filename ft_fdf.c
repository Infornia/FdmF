/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/02 18:07:30 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_init(t_data *d, char *file)
{
	int		i;

	i = 0;
	d->file_name = file;
	d->x_win = X_WIN;
	d->y_win = Y_WIN;
	d->projection_type = PARA;
	d->draw_type = IMG;
	d->size_map = 25;
	d->size_peaks = 15;
	d->move_lr = 1;
	d->move_ud = 1;
	d->mlx = mlx_init();
	d->win = mlx_new_window (d->mlx, d->x_win, d->y_win, "FdF");
	d->img = mlx_new_image(d->mlx, d->x_win, d->y_win);
	d->data_img = mlx_get_data_addr(d->img, &(d->color), &(d->size), &(d->endian));
	get_map(d);
	if (d->win)
	{
		mlx_key_hook(d->win, key_hook, d);
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
	draw_rainbow(d, d->x_win, d->y_win);
	print_map(d);
	return(0);
}

int		key_hook(int keycode, t_data *d)
{
	printf("Key %d\n", keycode);
	if (d)
	{
		if (keycode == 65307)
			ft_fdf_exit(d);
		if (keycode == 65361)
			move_left(d);
		if (keycode == 65363)
			move_right(d);
		if (keycode == 65362)
			move_up(d);
		if (keycode == 65364)
			move_down(d);
		if (keycode == 49)
		{
			d->projection_type = PARA;
			erase_img(d);
		}
		if (keycode == 50)
		{
			d->projection_type = ISO;
			erase_img(d);
		}
	printf("LR %d\n UD %d\n Proj %d\n", d->move_lr, d->move_ud, d->projection_type);
	}
	return (0);
}

int		mouse_hook(int	button, int x, int y, t_data *d)
{
	//printf("Mouse Button: %d\n", button);
	if (button == 1 && x > (d->x_win - 25) && y < 25)
		ft_fdf_exit(d);
	//printf("Mouse x: %d\n", x);
	//printf("Mouse y: %d\n", y);
	return (0);
}
