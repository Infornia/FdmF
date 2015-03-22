/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 16:33:11 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/20 16:37:02 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tree_h(t_tree *node)
{
	int	h;
	int	left_h;
	int	right_h;
	int	max;

	h = 0;
	if (node)
	{
		left_h = ft_tree_h(node->left);
		right_h = ft_tree_h(node->right);
		max = (left_h > right_h) ? left_h : right_h;
		h = 1 + max;
	}
	return (h);
}
