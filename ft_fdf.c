/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/31 21:54:05 by mwilk            ###   ########.fr       */
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
	d->projection_type = ISO;
	d->draw_type = IMG;
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
	//draw_rainbow(d, d->x_win, d->y_win);
	print_map(d);
	//check_case(d);
	//mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return(0);
}

int		key_hook(int keycode, t_data *d)
{
	//printf("Key %d\n", keycode);
	if (keycode >= 97 && keycode <= 122)
		color_set(keycode, d);
	if (d)
	{
		if (keycode == 65307)
			ft_fdf_exit(d);
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
