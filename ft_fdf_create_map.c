/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_create_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:39:19 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/01 20:38:03 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_map(t_data *d)
{
	t_map	*map;
	int		fd;
	int		y;
	char	**grid;
	char	*line;

	y = 0;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->map_h = line_count(d->file_name);
	map->z_max = 0;
	map->data = (t_point **)ft_memalloc(sizeof(t_point *) * map->map_h + 1); //alloc data[i]
	map->data[map->map_h + 1] = NULL;
	if (!(fd = open(d->file_name, O_RDONLY)))
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		map = split_int_this(map, line, y, d->projection_type);
		y++;
	}
	close(fd);
	d->map = map;
}

int			line_count(char *file_name)
{
	int		i;
	int		fd;
	char	**line;

	if (!(fd = open(file_name, O_RDONLY)))
		exit(0);
	line = ft_memalloc(sizeof(char **) * 2);
	i = 0;
	while ((get_next_line(fd, line) > 0))
		i++;
	free(line);
	close(fd);
	return (i);
}

t_point		create_point(int x, int y, int z, int proj)
{
	t_point	p;

	p.d3_x = x * 25;
	p.d3_y = y * 25;
	p.d3_z = z * 15;
	calc_proj(&p, proj);
	return (p);
}

t_map		*split_int_this(t_map *map, char *line, int y, int proj)
{
	char	**split;
	t_point	*atoi;
	int		tmp;
	int		x;
	int 	cur_x;

	x = 0;
	split = ft_strsplit(line, ' ');
	while ((split[x]) != NULL)
		x++;
	map->map_w = x > map->map_w ? x : map->map_w;
	cur_x = x;
	atoi = (t_point *)malloc(sizeof(t_point) * (x + 1)); //alloc data[i][x]
	x = 0;
	while (x < cur_x)
	{
		if ((tmp = ft_atoi((const char *)split[x])) > map->z_max)
			map->z_max = tmp;
		atoi[x] = create_point(x ,y, tmp, proj);
		x++;
	}
	map->data[y] = atoi;
	return (map);
}
