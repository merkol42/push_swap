/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:54:01 by merkol            #+#    #+#             */
/*   Updated: 2022/05/23 09:48:53 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		argc -= 2;
		onlyarg(&a, *(++argv), &argc);
		pushswap(&a, &b, argc);
	}
	else if (argc > 2)
	{
		argv++;
		while (*argv)
			filllist(&a, ft_atoi(*argv++));
		pushswap(&a, &b, argc - 1);
	}
}
	// while (b)
	// {
	// 	printf("B: rank: %d content: %d\n", b->rank, b->content);
	// 	b = b->next;
	// }
