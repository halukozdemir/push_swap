/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:33:57 by halozdem          #+#    #+#             */
/*   Updated: 2024/07/02 14:57:27 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_args_is_number(t_stacks *stacks);
static void		check_args_is_duplicate(t_stacks *stacks);
static void		check_is_int(t_stacks *stacks);

void	check_args(t_stacks *stacks, int ac)
{
	check_args_is_number(stacks);
	check_is_int(stacks);
	check_args_is_duplicate(stacks);
}

static void	check_args_is_number(t_stacks *stacks)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	args = stacks->args;
	while (args[i])
	{
		j = 0;
		if ((args[i][j] == '+' || args[i][j] == '-') && args[i][j + 1]
			&& args[i][j + 1] != '0')
			j++;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				put_error_and_free(stacks);
			j++;
		}
		i++;
	}
}

static void	check_is_int(t_stacks *stacks)
{
	int			i;
	char		**args;
	char		*str;
	int			num;

	i = 0;
	args = stacks->args;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		str = ft_itoa(num);
		if (ft_strncmp(str, args[i], ft_strlen(args[i])))
		{
			free(str);
			put_error_and_free(stacks);
		}
		free(str);
		i++;
	}
}

static void	check_args_is_duplicate(t_stacks *stacks)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	args = stacks->args;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[j]) == ft_atoi(args[i]))
				put_error_and_free(stacks);
			j++;
		}
		i++;
	}
}
