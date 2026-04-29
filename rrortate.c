/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrortate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:19:16 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:19:19 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrstack(t_stack **l)
{
	t_stack	*prev;
	t_stack	*last;

	if (!l || !*l || !(*l)->next)
		return ;
	prev = NULL;
	last = *l;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *l;
	*l = last;
}

void	rra(t_stack **a, t_counters *counters)
{
	rrstack(a);
	counters->rra++;
	counters->total_ops++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b, t_counters *counters)
{
	rrstack(b);
	counters->rrb++;
	counters->total_ops++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, t_counters *counters)
{
	rrstack(a);
	rrstack(b);
	counters->rrr++;
	counters->total_ops++;
	write(1, "rrr\n", 4);
}
