/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:49:46 by nfaska            #+#    #+#             */
/*   Updated: 2025/01/24 17:14:00 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef OPS_H
# define OPS_H
# ifndef STACK_H
#  define STACK_H
#  include <stack.h>
# endif

void	sa_(int *arr);
void	sb_(int *arr);
void	ss_(int *a, int *b);
void	pa_(stack_a *a, stack_b *b);
void	pb_(stack_a *a, stack_b *b);
void	ra_(stack_a *a);
void	rb_(stack_b *b);
void	rr_(stack_a *a, stack_b *b);
void	rra_(stack_a *a);
void	rrb_(stack_b *b);
void	rrr_(stack_a *a, stack_b *b);

#endif
