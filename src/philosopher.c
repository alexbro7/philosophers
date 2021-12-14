/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:26:58 by alebross          #+#    #+#             */
/*   Updated: 2021/12/10 17:00:46 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher(int ac, char **av)
{
	t_data	p;

	if (check_arguments(ac, av) == 1)
		return (1);
	p = get_arguments(av, ac);
	p.nb += 0;
	return (0);
}
