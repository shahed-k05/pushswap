/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:17:55 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:17:57 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(const char *n)
{
	int	i;

	i = 0;
	if (n[i] == '-' || n[i] == '+')
		i++;
	if (!n[i])
		return (0);
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_dup(long value, char **argv, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ft_atol(argv[j]) == value)
			return (1);
		j++;
	}
	return (0);
}

void	error_check(char **argv)
{
	int		i;
	long	temp;

	i = 0;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		temp = ft_atol(argv[i]);
		if (temp < INT_MIN || temp > INT_MAX)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (ft_dup(temp, argv, i))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
