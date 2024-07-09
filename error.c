/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:33:41 by halozdem          #+#    #+#             */
/*   Updated: 2024/07/03 14:31:31 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error_and_free(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->args[i])
		free(stacks->args[i++]);
	free(stacks->args);
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
	free(stacks);
	ft_printf("Error\n");
	exit(-1);
}

void	free_stack(t_list *stack)
{
	t_list	*node;
	t_list	*temp;

	node = stack;
	while (node)
	{
		free(node->content);
		temp = node;
		node = node->next;
		free (temp);
	}
}
