/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:15:34 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 11:31:44 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int fd, int nb)
{
	char	c;

	if (nb == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(fd, nb / 10);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}

void	put_disorder(int fd, double disorder)
{
	int	int_part;
	int	frac_part;
	int	percent;

	percent = (int)(disorder * 10000);
	int_part = percent / 100;
	frac_part = percent % 100;
	ft_putnbr(fd, int_part);
	write(fd, ".", 1);
	if (frac_part < 10)
		write(fd, "0", 1);
	ft_putnbr(fd, frac_part);
}

void	write_strategy(t_counters *counters)
{
	char	*str;
	char	*comp;

	if (counters->strategy == SIMPLE)
	{
		str = "Simple";
		comp = "O(n²)";
	}
	else if (counters->strategy == MEDIUM)
	{
		str = "Medium";
		comp = "O(n√n)";
	}
	else
	{
		str = "Complex";
		comp = "O(n log n)";
	}
	write(2, str, ft_strlen(str));
	write(2, " / ", 3);
	write (2, comp, ft_strlen(comp));
}

void	write_ops(t_counters *count)
{
	write(2, "\n[bench] total_ops: ", 20);
	ft_putnbr(2, count->total_ops);
	write(2, "\n[bench] sa: ", 13);
	ft_putnbr(2, count->sa);
	write(2, " sb: ", 5);
	ft_putnbr(2, count->sb);
	write(2, " ss: ", 5);
	ft_putnbr(2, count->ss);
	write(2, " pa: ", 5);
	ft_putnbr(2, count->pa);
	write(2, " pb: ", 5);
	ft_putnbr(2, count->pb);
	write(2, "\n[bench] ra: ", 13);
	ft_putnbr(2, count->ra);
	write(2, " rb: ", 5);
	ft_putnbr(2, count->rb);
	write(2, " rr: ", 5);
	ft_putnbr(2, count->rr);
	write(2, " rra: ", 6);
	ft_putnbr(2, count->rra);
	write(2, " rrb: ", 6);
	ft_putnbr(2, count->rrb);
	write(2, " rrr: ", 6);
	ft_putnbr(2, count->rrr);
	write(2, "\n", 1);
}

void	write_bench(t_counters *count)
{
	write(2, "[bench] disorder: ", 18);
	put_disorder(2, count->initial_disorder);
	write(2, "%\n[bench] strategy: ", 20);
	write_strategy(count);
	write_ops(count);
}
