/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:21:28 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:21:35 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_min_to_top(t_stack **a, int min_index,
			t_counters *counters)
{
	t_stack	*temp;
	int		pos;
	int		size;
	int		i;

	pos = 0;
	temp = *a;
	i = 0;
	while (temp && temp->indx != min_index)
	{
		temp = temp->next;
		i++;
	}
	pos = i;
	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		while ((*a)->indx != min_index)
			ra(a, counters);
	}
	else
	{
		while ((*a)->indx != min_index)
			rra(a, counters);
	}
}

void	selection_simple_sort(t_stack **a, t_stack **b,
			t_counters *counters)
{
	t_stack	*temp;
	int		min_index;
	int		i;

	while (*a)
	{
		temp = *a;
		min_index = temp->indx;
		i = 0;
		while (temp)
		{
			if (temp->indx < min_index)
				min_index = temp->indx;
			temp = temp->next;
			i++;
		}
		rotate_min_to_top(a, min_index, counters);
		pb(a, b, counters);
	}
	while (*b)
		pa(a, b, counters);
}
