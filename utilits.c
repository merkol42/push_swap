/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:55:28 by merkol            #+#    #+#             */
/*   Updated: 2022/05/16 09:55:29 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error(void)
{
	putstr("Error");
	exit(1);
}

void	putstr(char *ptr)
{
	write(1, ptr, ft_strlen(ptr));
	write(1, "\n", 1);
}

size_t	ft_strlen(const char *ptr)
{
	size_t	counter;

	counter = 0;
	while (*ptr++)
		counter++;
	return (counter);
}

int	ft_atoi(char *ptr)
{
	long	number;
	int		isnegative;
	int		delimiter;

	number = 0;
	isnegative = 1;
	delimiter = 0;
	if (*ptr == '-')
		isnegative *= -1;
	if (*ptr == '-' || *ptr == '+')
	{
		ptr++;
		delimiter++;
	}
	while (*ptr)
	{
		if (!(*ptr >= 48 && *ptr <= 57))
			error();
		number = number * 10 + (*(ptr++) - 48);
		delimiter++;
	}
	number = number * isnegative;
	if (number > 2147483647 || number < -2147483648 || delimiter > 11)
		error();
	return ((int)number);
}

int	getmedian(t_list *liste)
{
	t_list	*temp;
	t_list	*iter;
	int		count;
	int		listesize;

	listesize = listsize(liste);
	temp = liste;
	while (temp)
	{
		count = 0;
		iter = liste;
		while (iter)
		{
			if (temp->rank > iter->rank)
				count++;
			iter = iter->next;
		}
		if (count == listesize / 2)
			return (temp->rank);
		temp = temp->next;
	}
	return (-1);
}
