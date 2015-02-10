/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:42:54 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/10 18:49:00 by mwilk            ###   ########.fr       */
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

# define X_WIN 2622
# define Y_WIN X_WIN/2
# define PARA	0
# define ISO	1
# define EYE	2
# define PUT	0
# define IMG	1

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
	int			d3_x;
	int			d3_y;
	int			d3_z;
	int		x;
	int		y;
	int		color;

}				t_point;

typedef struct s_map
{
	t_point	**data;
	int		z_max;
	int		map_h;
	int		map_w;
}				t_map;

typedef	struct	s_data
{
	char	*file_name;
	void	*mlx;
	void	*win;
	void	*img;
	char		*data_img;
	int			bpp;
	int			size;
	int			endian;
	int		color;
	int			color_mode;
	int			projection_type;
	int			draw_type;
	int		lr;
	int		ud;
	double		zoom;
	double		peaks;
	t_map	*map;
}			t_data;

int		color_set(int key_code, t_data *e);
#endif

/*
**Prototypes
*/

/*
*******************INIT
*/
void	ft_fdf_init(t_data *d, char *file);
int		expose_hook(t_data *d);
int		mouse_hook(int button, int x, int y, t_data *d);
int		key_hook(int keycode, t_data *d);
void	ft_fdf_exit(t_data *d);
void	erase_img(t_data *d);

/*
*******************PARSING
*/

void	get_map(t_data *d);
int			line_count(char *file_name);
t_map		*split_int_this(t_map *map, char *line, int y);
t_point 		create_point(int x, int y, int z);

/*
*******************DRAW
*/

void	draw_white(t_data *e, int size, void *mlx, void *win, int draw);
void	print_map(t_data *d);
void		draw_line(t_data *d, t_point p1, t_point *p2);
void			calc_para(t_data *d, t_point *p);
void			calc_iso(t_data *d, t_point *p);
void			calc_control(t_point *p);
void			change_proj(t_data *d);
void			check_case(t_data *e, t_point p1, t_point p2);
void				draw_case1(t_data *e, t_point p1, t_point p2);
void				draw_case2(t_data *e, t_point p1, t_point p2);
void	draw_rainbow(t_data *e, int size, void *mlx, void *win, int draw);
void		color_pixel(t_data *e, int color, int x, int y, int size);

/*
*******************MOVE
*/

void	move_left(t_data *d);
void	move_right(t_data *d);
void	move_up(t_data *d);
void	move_down(t_data *d);
void	less_zoom(t_data *d);
void	more_zoom(t_data *d);
void	less_peak(t_data *d);
void	more_peak(t_data *d);


/*
*******************INUTILISE
*/

void	load_data(t_data *d);
void	print_data(t_data *d);
