/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:54:12 by merkol            #+#    #+#             */
/*   Updated: 2022/05/16 09:54:16 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	findmin(t_list *liste, int which)
{
	int	counter;
	int	min;
	int	rank;

	counter = 0;
	rank = 0;
	min = liste->content;
	while (liste)
	{
		if (liste->content < min)
		{
			min = liste->content;
			rank = counter;
		}
		liste = liste->next;
	}
	if (which)
		return (min);
	return (rank);
}

int	findmax(t_list *liste, int which)
{
	int	counter;
	int	max;
	int	rank;

	counter = 0;
	rank = 0;
	max = liste->content;
	while (liste)
	{
		if (liste->content > max)
		{
			max = liste->content;
			rank = counter;
		}
		liste = liste->next;
		counter++;
	}
	if (which)
		return (max);
	return (rank);
}

void	movemintotop(t_list **liste)
{
	int	min;
	int	isra;

	min = findmin(*liste, MIN_VALUE);
	if (findmin(*liste, MIN_RANK) < listsize(*liste) / 2)
		isra = 1;
	else
		isra = 0;
	while ((*liste)->content != min)
	{
		if (isra)
			rotate_a(liste);
		else
			reverserotate_a(liste);
	}
}

void	movemaxtotop(t_list **liste)
{
	int	max;
	int	isleft;

	max = findmax(*liste, MAX_VALUE);
	if (findmax(*liste, MAX_RANK) < listsize(*liste) / 2)
		isleft = 1;
	else
		isleft = 0;
	while ((*liste)->content != max)
	{
		if (isleft)
			rotate_b(liste);
		else
			reverserotate_b(liste);
	}
}
