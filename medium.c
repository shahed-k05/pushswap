/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:14:12 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:14:32 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top_a(t_stack **a, int start, int chunk_size,
	t_counters *counters)
{
	int		pos;
	t_stack	*temp;

	pos = 0;
	temp = *a;
	while (temp && (temp->indx < start || temp->indx >= start + chunk_size))
	{
		temp = temp->next;
		pos++;
	}
	if (pos <= ft_lstsize(*a) / 2)
		ra(a, counters);
	else
		rra(a, counters);
}

static void	rotate_to_top_b(t_stack **b, int max, t_counters *counters)
{
	int		pos;
	t_stack	*temp;

	pos = 0;
	temp = *b;
	while (temp && temp->indx != max)
	{
		temp = temp->next;
		pos++;
	}
	if (pos <= ft_lstsize(*b) / 2)
		while ((*b)->indx != max)
			rb(b, counters);
	else
		while ((*b)->indx != max)
			rrb(b, counters);
}

static void	push_chunk(t_chunk *data)
{
	int	count;

	count = 0;
	while (count < data->chunk_size && *(data->a))
	{
		if ((*(data->a))->indx >= data->start
			&& (*(data->a))->indx < data->start + data->chunk_size)
		{
			pb(data->a, data->b, data->counters);
			count++;
		}
		else
			rotate_to_top_a(data->a,
				data->start,
				data->chunk_size,
				data->counters);
	}
}

static void	restore_stack(t_stack **a, t_stack **b, int max,
	t_counters *counters)
{
	while (*b)
	{
		rotate_to_top_b(b, max, counters);
		pa(a, b, counters);
		max--;
	}
}

void	chunk_medium_sort(t_stack **a, t_stack **b, t_counters *counters)
{
	int		size;
	int		chunk_size;
	int		i;
	t_chunk	data;

	size = ft_lstsize(*a);
	chunk_size = size / 5 + (size % 5 != 0);
	data.a = a;
	data.b = b;
	data.chunk_size = chunk_size;
	data.counters = counters;
	i = 0;
	while (i * chunk_size < size)
	{
		data.start = i * chunk_size;
		push_chunk(&data);
		i++;
	}
	restore_stack(a, b, size - 1, counters);
}
