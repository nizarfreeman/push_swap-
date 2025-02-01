/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:33:36 by nfaska            #+#    #+#             */
/*   Updated: 2025/01/24 17:33:47 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stack.h>

void	ra_(t_stack_a *a)
{
	int	tmp;
	int	i;

	if (a->top < 1)
		return ;
	tmp = a->arr[0];
	i = 0;
	while (i < a->top)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->top] = tmp;
}

void	rb_(t_stack_b *b)
{
	int	tmp;
	int	i;

	if (b->top < 1)
		return ;
	tmp = b->arr[0];
	i = 0;
	while (i < b->top)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->top] = tmp;
}

void	rr_(t_stack_a *a, t_stack_b *b)
{
	ra_(a);
	rb_(b);
}
