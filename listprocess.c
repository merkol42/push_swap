/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listprocess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:53:52 by merkol            #+#    #+#             */
/*   Updated: 2022/05/17 16:31:18 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*createlist(void)
{
	t_list	*liste;

	liste = (t_list *)malloc(sizeof(t_list));
	liste->next = NULL;
	liste->rank = 0;
	return (liste);
}

int	listsize(t_list *liste)
{
	int	count;

	count = 0;
	while (liste)
	{
		count++;
		liste = liste->next;
	}
	return (count);
}

int	filllist(t_list **liste, int number)
{
	t_list	*newlist;
	t_list	*holderlist;

	if (!(*liste))
	{
		*liste = createlist();
		(*liste)->content = number;
		return (1);
	}
	holderlist = *liste;
	while (holderlist->next)
		holderlist = holderlist->next;
	newlist = createlist();
	newlist->content = number;
	holderlist->next = newlist;
	return (1);
}

void	onlyarg(t_list **liste, char *arg, int *argc)
{
	char	*argholder;
	int		check;

	check = 0;
	while (*arg)
	{
		if (*arg != ' ')
		{
			if (!check)
				argholder = arg;
			check = 1;
		}
		else if (*arg == ' ')
		{
			*arg = 0;
			if (check)
				*argc += filllist(liste, ft_atoi(argholder));
			check = 0;
		}
		arg++;
	}
	if (check)
		*argc += filllist(liste, ft_atoi(argholder));
}

void	set_rank(t_list **liste)
{
	t_list	*holder;
	t_list	*holder2;

	if (!(*liste))
		return ;
	holder = *liste;
	while (holder)
	{
		holder2 = *liste;
		while (holder2)
		{
			if (holder->content > holder2->content)
				holder->rank++;
			holder2 = holder2->next;
		}
		holder = holder->next;
	}
	holder = *liste;
}
