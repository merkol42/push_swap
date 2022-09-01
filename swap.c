/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:55:17 by merkol            #+#    #+#             */
/*   Updated: 2022/05/16 09:55:18 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_list **liste)
{
	t_list	*liste1;
	t_list	*liste2;

	liste1 = (*liste);
	liste2 = (*liste)->next;
	liste1->next = liste2->next;
	liste2->next = liste1;
	(*liste) = liste2;
}

void	swap_a(t_list **a)
{
	if (!((*a)) || (!(*a)->next)
		|| ((*a)->next->content > (*a)->content))
		return ;
	swap(a);
	putstr("sa");
}

void	swap_b(t_list **b)
{
	if (!((*b)) || (!(*b)->next)
		|| ((*b)->next->content > (*b)->content))
		return ;
	swap(b);
	putstr("sb");
}

void	swap_both(t_list **a, t_list **b)
{
	if ((!((*a)) || (!(*a)->next))
		|| ((*a)->next->content > (*a)->content)
		|| (!((*b)) || (!(*b)->next))
		|| ((*b)->next->content > (*b)->content))
		return ;
	swap(a);
	swap(b);
	putstr("ss");
}
