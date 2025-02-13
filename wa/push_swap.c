#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	skip_spaces(const char **s);
void	sign_check(const char	**s, int *flag, int *double_sign);
int	ll_check(unsigned long long res, int flag, int *flag_2);
int	ft_atoi(const char *s, int *flag_2);
int	count_words(const char *s, char c);
int	get_len(const char *s, char c);
void	free_array(char **arr);
void	skip_delim(const char	**s, char c);
char	**ft_split(const char *s, char c);
int	ft_isdigit(int c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int n)
{
	long	num;

	num = (long) n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}

typedef struct   a
{
	int	*arr;
	int	size;
	int	top;
} t_stack_a;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				index;
}	t_list;


void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
		temp = temp -> next;
	temp -> next = new;
}

void	lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}

int	lstsize(t_list *lst)
{
	size_t	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL)
		return ;
	if (lstsize(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;

	if (*stack_a == NULL)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	lstadd_front(stack_b, first);
}

void	rotate(t_list **stack)
{
	t_list	*first;

	if (*stack == NULL)
		return ;
	if (lstsize(*stack) < 2)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	lstadd_back(stack, first);
}

void	reverse_rotate(t_list **stack)
{
	int		size;
	t_list	*head;
	t_list	*current;

	if (*stack == NULL)
		return ;
	if (lstsize(*stack) < 2)
		return ;
	head = *stack;
	size = lstsize(*stack) - 1;
	while (size)
	{
		if (size == 1)
		{
			current = head;
		}
		head = head->next;
		size--;
	}
	lstadd_front(stack, head);
	current->next = NULL;
}

int	dup_check(int *arr, int index)
{
	int	i;
	int	j;

	i = 0;
	while (i <= index)
	{
		j = i + 1;
		while (j <= index)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			i++;
			continue ;
		}
		if ((s[i] == '-' || s[i] == '+') && !ft_isdigit(s[i + 1]))
			return (0);
		if (s[i] != '-' && s[i] != '+' && !ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_if_empty(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (1);
		s++;
	}
	return (0);
}

int	count_string_nums(char *str)
{
	char	**arr;
	int	ret;
	int	i;

	arr = ft_split(str, ' ');
	if (!arr)
		return (0);
	ret = 0;
	i = 0;
	while (arr[i])
	{
		ret++;
		i++;
	}
	i = 0;
	free_array(arr);	
	return (ret);
}

int	count_elements(int ac, char **av)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
	{
		if (!check_valid(av[i]) || !check_if_empty(av[i]))
			return (0);
		total += count_string_nums(av[i]);
		i++;
	}
	return (total);
}

int	push_(t_stack_a **a, char **arr)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (arr[i])
	{
		(*a)->arr[++((*a)->top)] = ft_atoi(arr[i], &flag);
		if (!flag)
		{
			free_array(arr);
			return (0);
		}
		i++;
	}
	free_array(arr);
	return (1);
}

int	fill_stack(t_stack_a **a, int ac, char **av)
{
	char	**arr;
	int	i;
	int	ret;

	i = 1;
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (!arr)
			return (0);
		ret = push_(a, arr);
		if (!ret)
			return (0);
		i++;
	}
	return (1);
}

int	set_a(t_stack_a **a, int ac, char **av)
{
	int	count;

	count = count_elements(ac, av);
	if (!count || ac == 1)
		return (0);
	*a = malloc(sizeof(t_stack_a));
	if (!*a)
		return (0);
	(*a)->arr = malloc(count * sizeof(int));
	if (!(*a)->arr)
	{
		free(*a);
		return (0);
	}
	(*a)->top = -1;
	(*a)->size = count;
	if (!fill_stack(a, ac, av) || !dup_check((*a)->arr, (*a)->top))
	{
		free((*a)->arr);
		free(*a);
		return (0);
	}
	return (1);
}

int	is_sorted(t_stack_a *a)
{
	int i;
	
	if (a->top < 1)
		return (1);
	i = 0;
	while (i < a->top)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_list *create_new_node(int value, int index)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = (void *)(long)value;
	new->index = index;
	new->next = NULL;
	return (new);
}

void free_list(t_list *head)
{
	t_list *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

int	smaller_than_i(int i, t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
	i++;
	return (i);
}

int	smaller_than_ij(int i, t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
	rotate(stack_b);
	ft_putstr("rb\n");
	i++;
	return (i);
}

void	not_i_not_ij(int parity, t_list **stack_a)
{
	if (parity == 1)
	{
		reverse_rotate(stack_a);
		ft_putstr("rra\n");
	}
	else
	{
		rotate(stack_a);
		ft_putstr("ra\n");
	}
}

void	put_index(t_list **stack, int index, int element)
{
	t_list	*head;
	int		size;

	head = *stack;
	size = lstsize(*stack);
	while (size)
	{
		if (*(int *)(head->content) == element)
		{
			head->index = index;
			break ;
		}
		head = head->next;
		size--;
	}
}

void	sort_index(t_list **stack)
{
	int		size;
	t_list	*head;
	int		x;
	int		indexing;

	indexing = lstsize(*stack) - 1;
	while (indexing + 1)
	{
		size = lstsize(*stack);
		x = -2147483648;
		head = *stack;
		while (size)
		{
			if ((*(int *)(head->content) > x) && head->index == 0)
				x = *(int *)(head->content);
			head = head->next;
			size--;
		}
		put_index(stack, indexing, x);
		indexing--;
	}
}

int	even(t_list *head, int count)
{
	while (head)
	{
		if ((*(int *)head->content % 2) == 0)
			count++;
		else
			break ;
		head = head->next;
	}
	return (count);
}

int	odd(t_list *head, int count)
{
	while (head)
	{
		if ((*(int *)head->content % 2) != 0)
			count++;
		else
			break ;
		head = head->next;
	}
	return (count);
}

int	even_odd(t_list **stack)
{
	int		parity;
	int		count;
	t_list	*head;
	int		size;

	(1) && (parity = 0, count = 0, head = *stack, size = lstsize(*stack));
	if ((*(int *)head->content % 2) != 0)
		parity = 1;
	if (parity == 0)
		count = even(head, count);
	else
		count = odd(head, count);
	if (count == size)
		return (0);
	if (count >= size / 3)
		return (1);
	return (0);
}

void	move_to_b(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*head_a;
	int		j;
	int		size;
	int		parity;

	i = 0;
	head_a = *stack_a;
	j = 16;
	parity = even_odd(stack_a);
	size = lstsize(*stack_a);
	if (size > 100)
		j = 36;
	while (head_a)
	{
		if (head_a->index <= i)
			i = smaller_than_i(i, stack_a, stack_b);
		else if (head_a->index <= i + j)
			i = smaller_than_ij(i, stack_a, stack_b);
		else
			not_i_not_ij(parity, stack_a);
		head_a = *stack_a;
	}
}

void	index_all(t_list **stack)
{
	t_list	*head;
	int		i;

	head = *stack;
	i = 0;
	while (head)
	{
		head->index = i;
		head = head->next;
		i++;
	}
}

int	get_s_position(t_list **stack)
{
	int		x;
	t_list	*head;

	x = 2147483647;
	head = *stack;
	while (head)
	{
		if (*(int *)head->content < x)
		{
			x = *(int *)head->content;
		}
		head = head->next;
	}
	head = *stack;
	while (head)
	{
		if (*(int *)head->content == x)
		{
			x = head->index;
			break ;
		}
		head = head->next;
	}
	return (x);
}

int	get_b_position(t_list **stack)
{
	int		x;
	t_list	*head;

	x = -2147483648;
	head = *stack;
	while (head)
	{
		if (*(int *)head->content > x)
		{
			x = *(int *)head->content;
		}
		head = head->next;
	}
	head = *stack;
	while (head)
	{
		if (*(int *)head->content == x)
		{
			x = head->index;
			break ;
		}
		head = head->next;
	}
	return (x);
}

void	move_to_a(t_list **stack_a, t_list **stack_b)
{
	int	position;
	int	size;

	size = lstsize(*stack_b);
	while (size)
	{
		index_all(stack_b);
		position = get_b_position(stack_b);
		if (position == 0)
		{
			push(stack_b, stack_a);
			ft_putstr("pa\n");
			size--;
		}
		else if (position <= size / 2)
		{
			rotate(stack_b);
			ft_putstr("rb\n");
		}
		else if (position > size / 2)
		{
			reverse_rotate(stack_b);
			ft_putstr("rrb\n");
		}
	}
}

t_list	*new_list(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list	*create_list(int *arr, int size)
{
	t_list	*head;
	t_list	*current;
	int		i;
	int		*value;
	t_list	*new_node;

	if (size <= 0)
		return (NULL);
	(1) && (head = NULL, current = NULL, i = 0);
	while (i < size)
	{
		value = malloc(sizeof(int));
		if (!value)
			return (NULL);
		(1) && (*value = arr[i], new_node = new_list(value));
		if (!new_node)
			return (NULL);
		if (!head)
			(1) && (head = new_node, current = head);
		else
			(1) && (current->next = new_node, current = new_node);
		i++;
	}
	return (head);
}

void	pos_zero(t_list **stack_a)
{
	int	s_position;

	s_position = get_s_position(stack_a);
	if (s_position == 1)
	{
		rotate(stack_a);
		ft_putstr("ra\n");
	}
	else
	{
		rotate(stack_a);
		ft_putstr("ra\n");
		swap(stack_a);
		ft_putstr("sa\n");
	}
}

void	pos_one(t_list **stack_a)
{
	int	s_position;

	s_position = get_s_position(stack_a);
	if (s_position == 0)
	{
		swap(stack_a);
		ft_putstr("sa\n");
		rotate(stack_a);
		ft_putstr("ra\n");
	}
	else
	{
		reverse_rotate(stack_a);
		ft_putstr("rra\n");
	}
}

void	pos_two(t_list **stack_a)
{
	int	s_position;

	s_position = get_s_position(stack_a);
	if (s_position == 1)
	{
		swap(stack_a);
		ft_putstr("sa\n");
	}
}

void	three_elements(t_list **stack_a)
{
	int	b_position;

	index_all(stack_a);
	b_position = get_b_position(stack_a);
	if (b_position == 0)
		pos_zero(stack_a);
	else if (b_position == 1)
		pos_one(stack_a);
	else
		pos_two(stack_a);
}

void	s_up(t_list **stack)
{
	int	s_position;

	index_all(stack);
	s_position = get_s_position(stack);
	while (s_position != 0)
	{
		if (s_position <= 2)
		{
			rotate(stack);
			ft_putstr("ra\n");
		}
		else if (s_position > 2)
		{
			reverse_rotate(stack);
			ft_putstr("rra\n");
		}
		index_all(stack);
		s_position = get_s_position(stack);
	}
}

void	five_elements(t_list **stack_a, t_list **stack_b)
{
	s_up(stack_a);
	push(stack_a, stack_b);
	ft_putstr("pb\n");
	s_up(stack_a);
	push(stack_a, stack_b);
	ft_putstr("pb\n");
	three_elements(stack_a);
	push(stack_b, stack_a);
	push(stack_b, stack_a);
	ft_putstr("pa\npa\n");
}

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = lstsize(*stack_a);
	if (size == 3)
		three_elements(stack_a);
	else
		five_elements(stack_a, stack_b);
}

void	sort(t_list **s1, t_list **s2)
{
	sort_index(s1);
	move_to_b(s1, s2);
	move_to_a(s1, s2);
}

void    print_list(t_list *head)
{
	t_list  *current;

	current = head;
	while (current)
	{
		int value = *(int*)(current->content);
		ft_putnbr(value);
		ft_putstr(" (index: ");
		ft_putnbr(current->index);
		ft_putstr(")\n");
		current = current->next;
	}
}

void	clean_up(t_stack_a *a, t_list *s1, t_list *s2)
{
	t_list *tmp;

	if (a)
	{
		free(a->arr);
		free(a);
	}
	while (s1)
	{
		tmp = s1->next;
		free(s1->content);
		free(s1);
		s1 = tmp;
	}
	while (s2)
	{
		tmp = s2->next;
		free(s2->content);
		free(s2);
		s2 = tmp;
	}
}

int main(int ac, char **av)
{
	t_stack_a *a;
	t_list *s1;
	t_list *s2;
	
	if (ac < 2)
		return (0);
	if (!set_a(&a, ac, av))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	s1 = create_list(a->arr, a->size);
	s2 = NULL;
	if (is_sorted(a))
	{
		clean_up(a, s1, s2);
		return (0);
	}
	if (lstsize(s1) <= 5)
		sort_small(&s1, &s2);
	else
		sort(&s1, &s2);
    print_list(s1);
    clean_up(a, s1, s2);
	return (0);
}

void	skip_spaces(const char	**s)
{
	while ((**s >= 9 && **s <= 13) || **s == ' ')
		(*s)++;
}

void	sign_check(const char **s, int *flag, int *double_sign)
{
	if (**s == '-' || **s == '+')
	{
		if (*(*s + 1) == '+' || (*(*s + 1)) == '-')
		{
			*double_sign = 1;
			return ;
		}
		if (**s == '-')
			*flag = 1;
		(*s)++;
	}
}

int	ll_check(unsigned long long res, int flag, int *flag_2)
{
	if (res > INT_MAX)
	{
		if (flag == 1 && res == 2147483648ULL)
			return (-2147483648);
		if (flag == 1)
		{
			*flag_2 = 0;
			return (0);
		
		}
		else
		{
			*flag_2 = 0;
			return (-1);
		}
	}
	return (1);
}

int	ft_atoi(const char *s, int *flag_2)
{
	unsigned long long	res;
	int					flag;
	int					double_sign;
	int					check;

	flag = 0;
	double_sign = 0;
	skip_spaces(&s);
	sign_check(&s, &flag, &double_sign);
	if (double_sign)
		return (0);
	res = 0;
	check = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		check = ll_check(res, flag, flag_2);
		if (check != 1)
			return (check);
		s++;
	}
	if (flag)
		return ((int)(-res));
	return ((int)res);
}


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	count_words(const char *s, char c)
{
	int	count;
	int	flag;

	if (!s)
		return (0);
	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

int	get_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	skip_delim(const char	**s, char c)
{
	while (**s == c)
		(*s)++;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	y;

	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	i = 0;
	while (s && *s && res)
	{
		y = 0;
		skip_delim(&s, c);
		if (!*s)
			break ;
		res[i] = (char *) malloc((get_len(s, c) + 1) * sizeof(char));
		if (!res[i])
		{
			free_array(res);
			return (NULL);
		}
		while (*s && *s != c)
			res[i][y++] = *s++;
		res[i++][y] = '\0';
	}
	if (res)
		res[i] = NULL;
	return (res);
}
