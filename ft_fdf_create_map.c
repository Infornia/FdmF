/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_create_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:39:19 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/02 18:11:05 by mwilk            ###   ########.fr       */
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
		map = split_int_this(map, line, y);
		y++;
	}
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
	atoi = (t_point *)malloc(sizeof(t_point) * (map->map_w + 1)); //alloc data[i][x]
	x = 0;
	while (split[x])
	{
		if ((tmp = ft_atoi((const char *)split[x])) > map->z_max)
			map->z_max = tmp;
		atoi[x] = create_point(x++ ,y, tmp);
	}
	while (x < map->map_w)
		atoi[x] = create_point(x++, y, 0);
	map->data[y] = atoi;
	return (map);
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

t_point		create_point(int x, int y, int z)
{
	t_point	p;

	p.d3_x = x * 25;
	p.d3_y = y * 25;
	p.d3_z = z * 15;
	return (p);
}
