/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:34:05 by nfaska            #+#    #+#             */
/*   Updated: 2025/01/24 17:34:23 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stack.h>

void	rra_(t_stack_a *a)
{
	int	tmp;
	int	i;

	if (a->top < 1)
		return ;
	tmp = a->arr[a->top];
	i = a->top;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = tmp;
}

void	rrb_(t_stack_b *b)
{
	int	tmp;
	int	i;

	if (b->top < 1)
		return ;
	tmp = b->arr[b->top];
	i = b->top;
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = tmp;
}

void	rrr_(t_stack_a *a, t_stack_b *b)
{
	rra_(a);
	rrb_(b);
}
