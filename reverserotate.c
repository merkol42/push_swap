/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:54:48 by merkol            #+#    #+#             */
/*   Updated: 2022/05/16 09:54:50 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverserotate(t_list **liste)
{
	t_list	*holder;
	t_list	*holder2;

	holder = *liste;
	holder2 = *liste;
	while (holder->next)
	{
		if (!(holder->next->next))
			holder2 = holder;
		holder = holder->next;
	}
	holder2->next = NULL;
	holder2 = *(liste);
	holder->next = holder2;
	*liste = holder;
}

void	reverserotate_a(t_list **a)
{
	if ((!(*a)) || !((*a)->next))
		return ;
	reverserotate(a);
	putstr("rra");
}

void	reverserotate_b(t_list **b)
{
	if ((!(*b)) || !((*b)->next))
		return ;
	reverserotate(b);
	putstr("rrb");
}

void	reverserotate_both(t_list **a, t_list **b)
{
	if ((!(*a)) || !((*a)->next)
		|| (!(*b)) || !((*b)->next))
		return ;
	reverserotate(a);
	reverserotate(b);
	putstr("rrr");
}
