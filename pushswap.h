/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:55:42 by merkol            #+#    #+#             */
/*   Updated: 2022/05/16 09:55:46 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_VALUE 1
# define MIN_VALUE 1
# define MAX_RANK 0
# define MIN_RANK 0

typedef struct s_list{
	int					content;
	unsigned int		rank;
	struct s_list		*next;
}	t_list;

void	error(void);
void	putstr(char *ptr);
size_t	ft_strlen(const char *ptr);
int		ft_atoi(char *ptr);
int		getmedian(t_list *liste);
t_list	*createlist(void);
int		listsize(t_list *liste);
void	set_rank(t_list **liste);
int		filllist(t_list **liste, int number);
void	onlyarg(t_list **liste, char *arg, int *argc);
void	checklist(t_list *liste);
int		checksort(t_list *liste);
int		lowerthanmedian(t_list *liste, int median);
int		findmin(t_list *liste, int which);
int		findmax(t_list *liste, int which);
void	movemintotop(t_list **liste);
void	movemaxtotop(t_list **liste);
void	push(t_list **liste1, t_list **liste2);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	swap(t_list **liste);
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_both(t_list **a, t_list **b);
void	rotate(t_list **liste);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_both(t_list **a, t_list **b);
void	reverserotate(t_list **liste);
void	reverserotate_a(t_list **a);
void	reverserotate_b(t_list **b);
void	reverserotate_both(t_list **a, t_list **b);
void	radix(t_list **a, t_list **b);
void	lessthan3(t_list **a);
void	wheels(t_list **a, t_list **b);
void	bucket(t_list **a, t_list **b);
void	pushswap(t_list **a, t_list **b, int argc);

#endif
/*
# define pb push_b(a, b, counter)
# define pa push_a(a, b, counter)
# define sa swap_a(a, counter)
# define sb swap_b(b, counter)
# define ss swap_both(a, b, counter)
# define ra rotate_a(a, counter)
# define rb rotate_b(b, counter)
# define rr rotate_both(a, b, counter)
# define rra reverserotate_a(a, counter)
# define rrb reverserotate_b(b, counter)
# define rrr reverserotate_both(a, b, counter)
*/
