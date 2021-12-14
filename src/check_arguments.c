/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:29:10 by alebross          #+#    #+#             */
/*   Updated: 2021/12/10 16:11:37 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arguments(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	if (ac < 5 || ac > 6)
		return (ft_error("Wrong number of arguments.") + 1);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (ft_error("Arguments must be positif numbers.") + 1);
			j++;
		}
		i++;
	}
	return (0);
}
