/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:57:55 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/13 22:59:53 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = new_stacks();
	if (ac < 2)
	{
		free(stacks);
		exit(0);
	}
	stacks->args = parse_args(ac, av, stacks);
	check_args(stacks, ac);
	add_args_to_stack(stacks);
	action_optimise(stacks);
	free_stack(stacks->stack_a);
	free(stacks);
}
