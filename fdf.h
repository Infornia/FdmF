/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:42:54 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/28 19:01:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include "libft/includes/libft.h"

/*
**Parameters
*/

# define X_WIN 1222
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
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))


/*
**Structures
*/

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;

}				t_point;

typedef struct s_mesh
{
	int		**data;
	int		z_max;
	int		map_h;
	int		map_w;
}				t_mesh;

typedef	struct	s_data
{
	char	*file_name;
	void	*mlx;
	void	*win;
	void	*img;
	char		*data_img;
	int			size;
	int			endian;
	int		x_win;
	int		y_win;
	int		color;
	t_mesh	*map;
}			t_data;

int		color_set(int key_code, t_data *e);
#endif

/*
**Prototypes
*/
void	ft_fdf_init(t_data *d, char *file);
int		expose_hook(t_data *d);
int		mouse_hook(int button, int x, int y, t_data *d);
int		key_hook(int keycode, t_data *d);
void	ft_fdf_exit(t_data *d);
void	draw(t_data *d, int x_win, int y_win);
void	check_case(t_data *e);

void	load_data(t_data *d);
void	print_data(t_data *d);
void	print_map(t_data *d);
void	get_map(t_data *d);
