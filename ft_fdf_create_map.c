/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_create_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:39:19 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 19:10:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_map(t_data *d)
{
	t_map	*map;
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->map_h = line_count(d->file_name);
	map->z_max = 0;
	map->data = (t_point **)ft_memalloc(sizeof(t_point *) * map->map_h);
	if (!(fd = open(d->file_name, O_RDONLY)))
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		map = split_int_this(map, line, y);
		ft_strdel(&line);
		++y;
	}
	free(line);
	close(fd);
	d->map = map;
}

t_map		*split_int_this(t_map *map, char *line, int y)
{
	char	**split;
	t_point	*atoi;
	int		tmp;
	int		x;

	x = 0;
	split = ft_strsplit(line, ' ');
	while ((split[x]) != NULL)
		x++;
	map->map_w = x > map->map_w ? x : map->map_w;
	atoi = (t_point *)malloc(sizeof(t_point) * (map->map_w + 1));
	x = 0;
	while (split[x])
	{
		if ((tmp = ft_atoi((const char *)split[x])) > map->z_max)
			map->z_max = tmp;
		free(split[x]);
		atoi[x] = create_point(&x ,y, tmp);
	}
	while (x < map->map_w)
		atoi[x] = create_point(&x, y, 0);
	map->data[y] = atoi;
	free(split);
	return (map);
}

int			line_count(char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	if (!(fd = open(file_name, O_RDONLY)))
		exit(0);
	i = 0;
	line = NULL;
	while ((get_next_line(fd, &line) > 0))
	{
		ft_strdel(&line);
		++i;
	}
	free(line);
	close(fd);
	return (i);
}

t_point		create_point(int *x, int y, int z)
{
	t_point	p;

	p.d3_x = *x;
	p.d3_y = y;
	p.d3_z = z;
	(*x) += 1;
	return (p);
}
