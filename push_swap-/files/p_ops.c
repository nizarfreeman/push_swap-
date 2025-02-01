/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:18:01 by nfaska            #+#    #+#             */
/*   Updated: 2025/01/24 17:30:56 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stack.h>

void	pa_(t_stack_a *a, t_stack_b *b)
{
	if (b->top == -1 || a->top + 1 >= a->size)
		return ;
	a->arr[++(a->top)] = b->arr[(b->top)--];
}

void	pb_(t_stack_a *a, t_stack_b *b)
{
	if (a->top == -1 || b->top + 1 >= b->size)
		return ;
	b->arr[++(b->top)] = a->arr[(a->top)--];
}
