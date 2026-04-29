/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:13:58 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 10:57:47 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**handle_args(int argc, char **argv, int start, int *allocated)
{
	*allocated = 0;
	if (start >= argc)
		return (NULL);
	if (argc - start == 1)
	{
		*allocated = 1;
		return (ft_split(argv[start], ' '));
	}
	return (argv + start);
}

static int	parse_flags(int argc, char **argv, t_vars *vars, int *bench)
{
	int	i;

	i = 1;
	*bench = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (-1);
	if (!ft_strcmp(argv[i], "--bench"))
	{
		*bench = 1;
		i++;
	}
	vars->mode = parse_flag(argv[i]);
	if (vars->mode != NO_FLAG)
		i++;
	else
		vars->mode = ADAPTIVE;
	return (i);
}

static void	init_program(t_vars *vars, int argc, char **argv,
			int *bench)
{
	int	i;

	ft_bzero(vars, sizeof(t_vars));
	i = parse_flags(argc, argv, vars, bench);
	if (i < 0)
		return ;
	vars->args = handle_args(argc, argv, i, &vars->allocated);
	error_check(vars->args);
	init_stack(&vars->a, vars->args);
	index_stack(vars->a);
	vars->counters.initial_disorder = compute_disorder(vars->a);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	int			bench;

	init_program(&vars, argc, argv, &bench);
	if (!is_sorted(vars.a))
		sort_stack(&vars.a, &vars.b, vars.mode, &vars.counters);
	if (bench)
		write_bench(&vars.counters);
	free_stack(vars.a);
	free_stack(vars.b);
	if (vars.allocated)
		free_args(vars.args);
	return (0);
}
