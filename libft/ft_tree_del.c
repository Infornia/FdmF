/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 16:37:09 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/20 16:49:22 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_del(t_tree **parent, void (*del)(void *, size_t))
{
	t_tree	*tmp;

	tmp = *parent;
	if (tmp)
	{
		ft_tree_del(&tmp->left, del);
		ft_tree_del(&tmp->right, del);
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
		*parent = NULL;
	}
}
