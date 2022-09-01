/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:54:59 by merkol            #+#    #+#             */
/*   Updated: 2022/05/16 09:55:01 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list **liste)
{
	t_list	*holder;
	t_list	*holder2;

	holder = *liste;
	holder2 = *liste;
	while (holder->next)
		holder = holder->next;
	(*liste) = (*liste)->next;
	holder->next = holder2;
	holder2->next = NULL;
}

void	rotate_a(t_list	**a)
{
	if ((!(*a)) || !((*a)->next))
		return ;
	rotate(a);
	putstr("ra");
}

void	rotate_b(t_list **b)
{
	if ((!(*b)) || !((*b)->next))
		return ;
	rotate(b);
	putstr("rb");
}

void	rotate_both(t_list **a, t_list **b)
{
	if ((!(*a)) || !((*a)->next)
		|| (!(*b)) || !((*b)->next))
		return ;
	rotate(a);
	rotate(b);
	putstr("rr");
}
