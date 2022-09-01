/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:54:27 by merkol            #+#    #+#             */
/*   Updated: 2022/05/16 09:54:28 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **liste1, t_list **liste2)
{
	t_list	*holder;
	t_list	*holder2;

	holder = *liste1;
	holder2 = *liste2;
	*liste1 = (*liste1)->next;
	*liste2 = holder;
	(*liste2)->next = holder2;
}

void	push_b(t_list **a, t_list **b)
{
	if (!(*a))
		return ;
	push(a, b);
	putstr("pb");
}

void	push_a(t_list **a, t_list **b)
{
	if (!(*b))
		return ;
	push(b, a);
	putstr("pa");
}
/*
 liste1 basini liste2 ye atiyor
*/
