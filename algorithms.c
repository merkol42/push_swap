/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:53:31 by merkol            #+#    #+#             */
/*   Updated: 2022/05/17 16:30:35 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	lessthan3(t_list **a)
{
	if ((*a)->next->next
		&& (*a)->next->next->content > (*a)->next->content
		&& (*a)->next->next->content < (*a)->content)
		rotate_a(a);
	swap_a(a);
	if (checksort(*a))
		return ;
	reverserotate_a(a);
	swap_a(a);
}

void	wheels(t_list **a, t_list **b)
{
	while (listsize(*a) != 3)
	{
		movemintotop(a);
		push_b(a, b);
	}
	lessthan3(a);
	while (*b)
		push_a(a, b);
}

void	bucket(t_list **a, t_list **b)
{
	int	median;

	while (listsize(*a) >= 3)
	{
		median = getmedian(*a);
		while (lowerthanmedian(*a, median))
		{
			if ((*a)->rank < (unsigned int)median)
				push_b(a, b);
			else
				rotate_a(a);
		}
	}
	lessthan3(a);
	while (*b)
	{
		movemaxtotop(b);
		push_a(a, b);
	}
}

void	radix(t_list **a, t_list **b)
{
	int		min_bit;
	int		i;
	int		j;

	min_bit = 0;
	j = listsize(*a);
	while (min_bit < 32)
	{
		i = 0;
		while (*a && i < j)
		{
			if ((((*a)->rank >> min_bit) & 1) == 0)
				push_b(a, b);
			else
				rotate_a(a);
			i++;
		}
		while (*b)
			push_a(a, b);
		if (checksort(*a))
			return ;
		min_bit++;
	}
}
