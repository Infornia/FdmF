/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/11 21:17:40 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

int		main(int ac, char **av)
{
	t_data	d;

	if (ac == 1)
	{
		ft_fdf(&d, av[1]);
	}
	return (0);
}