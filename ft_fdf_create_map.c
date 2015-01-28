/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_create_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:39:19 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/28 17:51:24 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		line_count(char *file_name)
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

t_mesh		*split_int_this(t_mesh *mesh, char *line, int i)
{
	char	**split;
	int		*atoi;
	int		tmp;
	int		x;
	int 	cur_x;

	x = 0;
	split = ft_strsplit(line, ' ');
	while ((split[x]) != NULL)
		x++;
	if (x > mesh->map_w)
		mesh->map_w = x;
	cur_x = x;
	atoi = ft_memalloc(sizeof(int *) * x + 1); //alloc data[i][x]
	x = 0;
	while (x < cur_x)
	{
		if ((tmp = ft_atoi((const char *)split[x])) > mesh->z_max)
			mesh->z_max = tmp;
		atoi[x] = tmp;
		x++;
	}
	mesh->data[i] = atoi;
	return (mesh);
}

void	get_map(t_data *d)
{
	t_mesh	*mesh;
	int		fd;
	int		i;
	char	**grid;
	char	*line;

	i = 0;
	mesh = ft_memalloc(sizeof(t_mesh));
	mesh->map_h = line_count(d->file_name);
	mesh->z_max = 0;
	mesh->data = (int **)ft_memalloc(sizeof(int **) * mesh->map_h + 1); //alloc data[i]
	if (!(fd = open(d->file_name, O_RDONLY)))
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		mesh = split_int_this(mesh, line, i);
		i++;
	}
	close(fd);
	printf("%i\n%i\n%i\n", mesh->map_h, mesh->map_w, mesh->z_max);
	d->map = mesh;
}
