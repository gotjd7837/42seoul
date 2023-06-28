#include "./include/push_swap.h"

static void	arr_duplicates_checker(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				print_error(0);
			j++;
		}
		i++;
	}
}

static void	arr_sort_checker(int *arr, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (arr[i] < arr[i - 1])
			return ;
		i++;
	}
	print_error(0);
}

void	handle_arg_error(int *stack_data, int size)
{
	arr_sort_checker(stack_data, size);
	quick_sort_arr(stack_data, 0, size - 1);
	arr_duplicates_checker(stack_data, size);
}



static char	*result_malloc(char *str, char c, char **result, int idx)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	result[idx] = (char *)malloc(sizeof(char) * (len + 1));
	if (result[idx] == NULL)
	{
		while (--idx >= 0)
			free(result[idx]);
		free(result);
		return (NULL);
	}
	ft_strlcpy(result[idx], str, len + 1);
	return (result[idx]);
}

static char	**result_double_malloc(char *str, char c)
{
	size_t	cnt;
	char	**result;

	cnt = 0;
	while (*str)
	{
		if (*str != c)
		{
			cnt++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**result;
	int		i;

	str = (char *)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	result = result_double_malloc(str, c);
	if (result == NULL)
		return (NULL);
	while (*str)
	{
		if (*str != c)
		{
			if (result_malloc(str, c, result, i++) == NULL)
				return (NULL);
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}



int	*stack_to_arr(t_stack *stack)
{
	t_node	*current_node;
	int		*arr;
	int		i;
	int		stack_size;

	i = 0;
	stack_size = stack->size;
	arr = (int *)malloc(sizeof(int) * stack_size);
	if (arr == NULL)
		return (NULL);
	current_node = stack->top->next;
	while (i < stack_size)
	{
		arr[i++] = current_node->content;
		current_node = current_node->next;
	}
	return (arr);
}

static long long	push_swap_atoi(const char *str)
{
	int			flag;
	long long	result;

	flag = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str++ - '0');
		else
			print_error(0);
	}
	return (result * flag);
}

static void	parse(t_stack *stack, char **split)
{
	t_node		*node;
	long long	arg;
	int			i;

	i = 0;
	while (split[i] != NULL)
	{
		arg = push_swap_atoi(split[i]);
		if (arg > 2147483647 || arg < -2147483648)
			print_error(0);
		node = new_node(arg);
		push_top_stack(stack, node);
		i++;
	}
}

int	*arg_parsing(t_stack *stack, int ac, char *av[])
{
	int		i;
	char	**split;
	int		*stack_data;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		parse(stack, split);
		i++;
	}
	if (stack->size == 0)
		print_error(1);
	stack_data = stack_to_arr(stack);
	handle_arg_error(stack_data, stack->size);
	return (stack_data);
}














t_node	*new_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->content = content;
	return (node);
}


void	print_error(int sign)
{
	if (sign == 0)
		write(1, "Error\n", 6);
	exit(1);
}




void	push_top_stack(t_stack *stack, t_node *ph_node)
{
	if (stack->size == 0)
	{
		stack->top->next = ph_node;
		stack->bottom->prev = ph_node;
		ph_node->prev = stack->top;
		ph_node->next = stack->bottom;
		stack->size += 1;
	}
	else
	{
		stack->top->next->prev = ph_node;
		ph_node->next = stack->top->next;
		stack->top->next = ph_node;
		ph_node->prev = stack->top;
		stack->size += 1;
	}
}

void	push_bottom_stack(t_stack *stack, t_node *ph_node)
{
	if (stack->size == 0)
	{
		stack->top->next = ph_node;
		stack->bottom->prev = ph_node;
		ph_node->prev = stack->top;
		ph_node->next = stack->bottom;
		stack->size += 1;
	}
	else
	{
		stack->bottom->prev->next = ph_node;
		ph_node->prev = stack->bottom->prev;
		stack->bottom->prev = ph_node;
		ph_node->next = stack->bottom;
		stack->size += 1;
	}
}

t_node	*pop_top_stack(t_stack *stack)
{
	t_node	*pop_node;

	pop_node = stack->top->next;
	if (stack->size == 0)
		return (NULL);
	else
	{
		pop_node->next->prev = stack->top;
		stack->top->next = pop_node->next;
		pop_node->prev = NULL;
		pop_node->next = NULL;
		stack->size -= 1;
		return (pop_node);
	}
}

t_node	*pop_bottom_stack(t_stack *stack)
{
	t_node	*pop_node;

	pop_node = stack->bottom->prev;
	if (stack->size == 0)
		return (NULL);
	else
	{
		pop_node->prev->next = stack->bottom;
		stack->bottom->prev = pop_node->prev;
		pop_node->prev = NULL;
		pop_node->next = NULL;
		stack->size -= 1;
		return (pop_node);
	}
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = new_node(0);
	stack->bottom = new_node(0);
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->size = 0;
	return (stack);
}









int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_data;

	if (ac > 2)
	{
		stack_a = init_stack();
		stack_b = init_stack();
		sorted_data = arg_parsing(stack_a, ac, av);
		// sort_stack(stack_a, stack_b, sorted_data);
	}
	else
		print_error(0);
	return (0);
}
