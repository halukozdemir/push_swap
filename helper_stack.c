/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:33:31 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/13 22:33:33 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*new_stacks(void)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->count_a = 0;
	stacks->count_b = 0;
	stacks->args = NULL;
	stacks->ra = 0;
	stacks->rb = 0;
	stacks->rr = 0;
	stacks->rra = 0;
	stacks->rrb = 0;
	stacks->rrr = 0;
	return (stacks);
}

void	add_args_to_stack(t_stacks *stacks)
{
	int		i;
	char	**args;
	int		*num;

	args = stacks->args;
	i = 0;
	while (args[i])
	{
		num = (int *)malloc(sizeof(int));
		if (num == NULL)
			put_error_and_free(stacks);
		*num = ft_atoi(args[i]);
		free(args[i++]);
		ft_lstadd_back(&stacks->stack_a, ft_lstnew(num));
		stacks->count_a++;
	}
	free(stacks->args);
}
