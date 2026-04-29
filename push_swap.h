/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:19:06 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 10:25:41 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef enum e_mode
{
	NO_FLAG = -1,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	COUNT_ONLY
}	t_mode;

typedef struct s_counters
{
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	initial_disorder;
	t_mode	strategy;
}	t_counters;

typedef struct s_stack
{
	int				value;
	int				indx;
	struct s_stack	*next;
}	t_stack;

typedef struct s_vars
{
	t_stack		*a;
	t_stack		*b;
	t_mode		mode;
	int			allocated;
	char		**args;
	double		disorder;
	t_counters	counters;
}	t_vars;

typedef struct s_chunk
{
	t_stack		**a;
	t_stack		**b;
	int			start;
	int			chunk_size;
	t_counters	*counters;
}	t_chunk;

t_mode	parse_flag(char *arg);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);

t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **ls, t_stack *new);
t_stack	*ft_lstlast(t_stack *ls);
int		ft_lstsize(t_stack *ls);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int fd, int n);
void	error_check(char **argv);
void	init_stack(t_stack **a, char **argv);
void	index_stack(t_stack *a);
int		is_sorted(t_stack *a);
void	sort_stack(t_stack **a, t_stack **b,
			t_mode mode, t_counters *counters);
void	ft_bzero(void *s, size_t n);

void	sa(t_stack **a, t_counters *counters);
void	sb(t_stack **b, t_counters *counters);
void	ss(t_stack **a, t_stack **b, t_counters *counters);
void	pa(t_stack **a, t_stack **b, t_counters *counters);
void	pb(t_stack **a, t_stack **b, t_counters *counters);
void	ra(t_stack **a, t_counters *counters);
void	rb(t_stack **b, t_counters *counters);
void	rr(t_stack **a, t_stack **b, t_counters *counters);
void	rra(t_stack **a, t_counters *counters);
void	rrb(t_stack **b, t_counters *counters);
void	rrr(t_stack **a, t_stack **b, t_counters *counters);

void	free_stack(t_stack *stack);
void	free_args(char **args);

void	selection_simple_sort(t_stack **a, t_stack **b,
			t_counters *counters);
void	chunk_medium_sort(t_stack **a, t_stack **b,
			t_counters *counters);
void	radix_complex_sort(t_stack **a, t_stack **b,
			t_counters *counters);

double	compute_disorder(t_stack *a);
void	write_bench(t_counters *counters);
void	put_disorder(int fd, double disorder);

#endif
