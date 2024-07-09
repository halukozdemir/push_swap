/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:58:17 by halozdem          #+#    #+#             */
/*   Updated: 2023/12/22 18:19:01 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((c >= 'a' && c <= 'z')) || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
		return (0);
}
