/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:42:54 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/17 19:29:43 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <mlx.h>

/*
**Parameters
*/

# define X_WIN 2200
# define Y_WIN X_WIN/2

/*
**Colors
*/
# define RED	0xFF0000
# define BLUE 	0x0000FF
# define GREEN 	0x00FF00
# define WHITE 	0xFFFFFF
# define BLACK 	0x000000
# define PINK 	0xFF00FF


/*
**Structures
*/
typedef	struct	s_data
{
	char	*file_name;
	void	*mlx;
	void	*win;
	int		x_win;
	int		y_win;
	int		color;
}			t_data;

int		color_set(int key_code, t_data *e);
#endif

/*
**Prototypes
*/
void	ft_fdf_init(t_data *d, char *file);
int		ft_fdf_expose_hook(t_data *d);
int		ft_fdf_key_hook(int keycode, t_data *d);
void	ft_fdf_exit(t_data *d);
void	draw(t_data *d, int x_win, int y_win);

void	get_grid(t_data *d);
