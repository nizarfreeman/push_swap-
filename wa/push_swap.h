/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:59:39 by nfaska            #+#    #+#             */
/*   Updated: 2025/02/13 18:24:36 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct a
{
	int	*arr;
	int	size;
	int	top;
}	t_stack_a;

typedef struct s_list
{
	int				index;
	void			*content;
	struct s_list	*next;
}	t_list;

void	skip_spaces(const char **s);
void	sign_check(const char	**s, int *flag, int *double_sign);
void	free_array(char **arr);
void	skip_delim(const char	**s, char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	lstadd_back(t_list **lst, t_list *new);
void	lstadd_front(t_list **lst, t_list *new);
void	swap(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	free_list(t_list *head);
void	not_i_not_ij(int parity, t_list **stack_a);
void	put_index(t_list **stack, int index, int element);
void	sort_index(t_list **stack);
void	move_to_b(t_list **stack_a, t_list **stack_b);
void	index_all(t_list **stack);
void	move_to_a(t_list **stack_a, t_list **stack_b);
void	pos_zero(t_list **stack_a);
void	pos_one(t_list **stack_a);
void	pos_two(t_list **stack_a);
void	three_elements(t_list **stack_a);
void	s_up(t_list **stack);
void	five_elements(t_list **stack_a, t_list **stack_b);
void	sort_small(t_list **stack_a, t_list **stack_b);
void	sort(t_list **s1, t_list **s2);
void	clean_up(t_stack_a *a, t_list *s1, t_list *s2);

int		ll_check(unsigned long long res, int flag, int *flag_2);
int		ft_atoi(const char *s, int *flag_2);
int		count_words(const char *s, char c);
int		get_len(const char *s, char c);
int		ft_isdigit(int c);
int		lstsize(t_list *lst);
int		dup_check(int *arr, int index);
int		check_valid(char *s);
int		check_if_empty(char *s);
int		count_string_nums(char *str);
int		count_elements(int ac, char **av);
int		push_(t_stack_a **a, char **arr);
int		fill_stack(t_stack_a **a, int ac, char **av);
int		set_a(t_stack_a **a, int ac, char **av);
int		is_sorted(t_stack_a *a);
int		smaller_than_i(int i, t_list **stack_a, t_list **stack_b);
int		smaller_than_ij(int i, t_list **stack_a, t_list **stack_b);
int		even(t_list *head, int count);
int		odd(t_list *head, int count);
int		even_odd(t_list **stack);
int		get_s_position(t_list **stack);
int		get_b_position(t_list **stack);

char	**ft_split(const char *s, char c);

t_list	*create_new_node(int value, int index);
t_list	*new_list(void *content);
t_list	*create_list(int *arr, int size);

#endif
