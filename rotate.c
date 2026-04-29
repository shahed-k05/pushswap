/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:17:16 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:17:22 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rstack(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	last = *s;
	while (last->next)
		last = last->next;
	*s = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **a, t_counters *counters)
{
	rstack(a);
	counters->ra++;
	counters->total_ops++;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b, t_counters *counters)
{
	rstack(b);
	counters->rb++;
	counters->total_ops++;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, t_counters *counters)
{
	rstack(a);
	rstack(b);
	counters->rr++;
	counters->total_ops++;
	write(1, "rr\n", 3);
}
