/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:33:23 by halozdem          #+#    #+#             */
/*   Updated: 2024/07/02 15:13:51 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_stacks *stacks);
static void	advanced_sort(t_stacks *stacks);

void	action_optimise(t_stacks *stacks)
{
	if (is_sort(stacks->stack_a))
		exit(0);
	if (stacks->count_a == 2)
		actions(stacks, "sa");
	else if (stacks->count_a == 3)
		three_sort(stacks);
	else
		advanced_sort(stacks);
}

static void	three_sort(t_stacks *stacks)
{
	if (max_stack(stacks->stack_a) == (t_list *)stacks->stack_a)
		actions(stacks, "ra");
	else if (min_stack(stacks->stack_a) == ft_lstlast(stacks->stack_a))
		actions(stacks, "rra");
	if (!is_sort(stacks->stack_a))
		actions(stacks, "sa");
	if (!is_sort(stacks->stack_a))
		actions(stacks, "ra");
}

static void	advanced_sort(t_stacks *stacks)
{
	actions(stacks, "pb");
	actions(stacks, "pb");
	while (stacks->count_a > 3)
	{
		find_a_index(stacks);
		push_to_b(stacks);
	}
	if (stacks->count_a == 3)
		three_sort(stacks);
	sort_b(stacks);
	push_to_a(stacks);
	sort_a(stacks);
}
