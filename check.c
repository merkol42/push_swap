/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:53:43 by merkol            #+#    #+#             */
/*   Updated: 2022/05/17 16:31:06 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checksort(t_list *liste)
{
	if (!liste || !(liste->next))
		return (1);
	while (liste->next)
	{
		if (liste->content > liste->next->content)
			return (0);
		liste = liste->next;
	}
	return (1);
}

void	checklist(t_list *liste)
{
	t_list	*holder;

	while (liste->next)
	{
		holder = liste->next;
		while (holder)
		{
			if (holder->content == liste->content)
				error();
			holder = holder->next;
		}
		liste = liste->next;
	}
}

int	lowerthanmedian(t_list *liste, int median)
{
	while (liste)
	{
		if (liste->rank < (unsigned int)median)
			return (1);
		liste = liste->next;
	}
	return (0);
}
