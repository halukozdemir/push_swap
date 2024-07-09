/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:33:15 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/13 22:33:18 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*convert_to_one_str(int ac, char **av);

char	**parse_args(int ac, char **av, t_stacks *stacks)
{
	char	*str;
	char	**result;

	str = convert_to_one_str(ac, av);
	result = ft_split(str, ' ');
	if (result[0] == NULL)
	{
		free(result[0]);
		free(result);
		free(stacks);
		exit(0);
	}
	return (free(str), result);
}

static char	*convert_to_one_str(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	if (ac == 2)
		str = ft_strdup(av[1]);
	else if (ac > 2)
	{
		str = ft_strdup("");
		while (++i < ac)
		{
			temp = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(temp, av[i]);
			free(temp);
		}
	}
	return (str);
}
