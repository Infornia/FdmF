/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:39:19 by mwilk             #+#    #+#             */
/*   Updated: 2015/01/12 23:34:41 by mwilk            ###   ########.fr       */
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

	x = 0;
	split = ft_strsplit(line, ' ');
	while ((split[x]) != NULL)
		x++;
	mesh->x = x;
	atoi = ft_memalloc(sizeof(int *) * x + 1);
	x = 0;
	while (x < mesh->x)
	{
		tmp = ft_atoi((const char *)split[x]);
		atoi[x] = tmp;
		printf("%i\n", atoi[x]);
		x++;
	}
	mesh->data[i] = atoi;
	return (mesh);
}

void		get_grid(t_data *d)
{
	t_mesh	*mesh;
	int		fd;
	int		i;
	char	**grid;
	char	*line;

	i = 0;
	mesh = ft_memalloc(sizeof(t_mesh));
	mesh->y = line_count(d->file_name);
	mesh->data = (int **)ft_memalloc(sizeof(int **) * mesh->y + 1);
	if (!(fd = open(d->file_name, O_RDONLY)))
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		mesh = split_int_this(mesh, line, i);
		i++;
	}
}
