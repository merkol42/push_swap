/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:54:39 by merkol            #+#    #+#             */
/*   Updated: 2022/05/17 16:31:36 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushswap(t_list **a, t_list **b, int argc)
{
	checklist(*a);
	set_rank(a);
	if (checksort(*a))
		return ;
	if (argc <= 3)
		lessthan3(a);
	else if (argc <= 5)
		wheels(a, b);
	else if (argc < 200)
		bucket(a, b);
	else
		radix(a, b);
	if (checksort(*a))
		exit(0);
}
	// t_list *tmp;
	// tmp = *a;
	// while (tmp)
	// {
	// 	printf("Data %d , Rank = %d\n", tmp->content, tmp->rank);
	// 	tmp = tmp->next;
	// }