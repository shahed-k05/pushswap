/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:16:52 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 11:26:57 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_3(t_stack **a, t_counters *counters)
{
	int	first;
	int	second;
	int	third;

	if (!*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, counters);
	else if (first > second && second > third)
	{
		sa(a, counters);
		rra(a, counters);
	}
	else if (first > second && second < third && first > third)
		ra(a, counters);
	else if (first < second && second > third && first < third)
	{
		sa(a, counters);
		ra(a, counters);
	}
	else if (first < second && second > third && first > third)
		rra(a, counters);
}

static void	select_auto_strategy(t_stack **a, t_stack **b, t_counters *counters)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 5)
	{
		counters->strategy = SIMPLE;
		selection_simple_sort(a, b, counters);
	}
	else if (size <= 100)
	{
		counters->strategy = MEDIUM;
		chunk_medium_sort(a, b, counters);
	}
	else
	{
		counters->strategy = COMPLEX;
		radix_complex_sort(a, b, counters);
	}
}

void	sort_stack(t_stack **a, t_stack **b, t_mode mode, t_counters *counters)
{
	if (is_sorted(*a))
		return ;
	if (ft_lstsize(*a) == 2)
		sa(a, counters);
	else if (ft_lstsize(*a) <= 3)
		sort_3(a, counters);
	else if (mode == SIMPLE)
	{
		counters->strategy = SIMPLE;
		selection_simple_sort(a, b, counters);
	}
	else if (mode == MEDIUM)
	{
		counters->strategy = MEDIUM;
		chunk_medium_sort(a, b, counters);
	}
	else if (mode == COMPLEX)
	{
		counters->strategy = COMPLEX;
		radix_complex_sort(a, b, counters);
	}
	else
		select_auto_strategy(a, b, counters);
}
