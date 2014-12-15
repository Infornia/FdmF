/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:26:26 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/08 20:33:33 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	freedom(char **to_red, char **line)
{
	*line = ft_strdup(*to_red);
	free(*to_red);
	*to_red = NULL;
}

static int	send_cut_and_keep(char **line, char **to_red, char **mother_cutter)
{
	*line = *to_red;
	**mother_cutter = '\0';
	*to_red = ft_strdup(*mother_cutter + 1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			bull[BUFF_SIZE + 1];
	static char		*to_red[256];
	char			*mother_cutter;
	int				ret;

	ret = 1;
	if (!to_red[fd])
	{
		if ((ret = read(fd, bull, BUFF_SIZE)) < 1)
			return (ret);
		bull[ret] = 0;
		to_red[fd] = ft_strdup(bull);
	}
	while (!ft_strchr(to_red[fd], '\n') && (ret = read(fd, bull, BUFF_SIZE)))
	{
		bull[ret] = 0;
		to_red[fd] = ft_strjoin(to_red[fd], bull);
	}
	if ((mother_cutter = ft_strchr(to_red[fd], '\n')))
		return (send_cut_and_keep(line, &to_red[fd], &mother_cutter));
	freedom(&to_red[fd], line);
	return (ft_strlen(*line) > 0);
}
