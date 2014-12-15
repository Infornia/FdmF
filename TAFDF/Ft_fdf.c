/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/11 21:17:31 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int		ft_fdf_init(t_data *d, char *file)
{
	int		i;

	i = 0;
	d->file_name = file;
	d->x_win = X_WIN;
	d->y_win = Y_WIN;
	d->mlx = mlx_init();
	if (d->mlx)
	{
		d->win = mlx_new_window (d->mlx, d->x_win, d->x_win/2, "FDF");
		mlx_key_hook(d->win, key_hook, d);
		mlx_expose_hook(d->win, ft_fdf_expose_hook, d);
		mlx_loop(d->mlx);
	}
	return (0);
}

void	ft_fdf_exit(t_data *d)
{
	exit(o);
}

int		ft_fdf_expose_hook(t_data *d)
{
	draw(*d, d->x_win, d->x_win/2);
	return(0);
}

int		ft_fdf_key_hook(int keycode, t_data *d)
{
	printf("Key %d\n", keycode);
	if (keycode >= 97 && keycode <= 122)
		color_set(keycode, d);
	if (d)
	{
		if (keycode == 65307)
			ft_fdf_exit(d);
	}
	printf("%d", WHITE);
	return (0);
}