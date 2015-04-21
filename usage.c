/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 19:35:22 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/21 20:12:59 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_print_usage(void)
{
	ft_putstr("\033[35m\n\t *****Welcome to Fdf*****\n\n\033[0m");
	ft_putstr("\033[32m\tusage: ./fdf [YourMap.txt]\n\n\033[0m");
	ft_putstr("\033[33m\t---------Commands---------\n");
	ft_putstr("\tProjections:");
	ft_putstr("\t\n\t\tPara =\t\tP\n\t\tIso =\t\tI\n\n");
	ft_putstr("\tPeaks:\n\t\tUp =\t\t]\n\t\tDown =\t\t[\n\n");
	ft_putstr("\tZoom:\n\t\tIn =\t\t+\n\t\tOut =\t\t-\n\n");
	ft_putstr("\tModes:\n\t\tRainbow =\t1\n\t\tLumino =\t2");
	ft_putstr("\n\t\tStrobo =\t3\n\t\tSpecial =\t4\n");
	ft_putstr("\t\tNormal =\t5\n\n");
	ft_putstr("\tMoves:\t\t\tArrows\n\n\033[0m");
	ft_putstr("\033[36m\tReset:\t\t\t0\n\033[0m");
	ft_putstr("\033[31m\tExit:\t\t\tesc\n\n\033[0m");
}
