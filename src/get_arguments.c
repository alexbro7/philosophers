/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:42:03 by alebross          #+#    #+#             */
/*   Updated: 2021/12/10 17:00:26 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	get_arguments(char **av, int ac)
{
	t_data		d;

	d.nb = ft_atoi(av[1]);
	d.die_t = ft_atoi(av[2]);
	d.eat_t = ft_atoi(av[3]);
	d.sleep_t = ft_atoi(av[4]);
	if (ac == 6)
		d.eat_nb = ft_atoi(av[5]);
	else
		d.eat_nb = -1;
	return (d);
}
