/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:29:21 by alebross          #+#    #+#             */
/*   Updated: 2021/12/14 17:43:09 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	d;

	if (check_arguments(ac, av) == 1)
		return (1);
	d = get_arguments(av, ac);
	if (!d.nb || !d.die_t || !d.eat_t || !d.sleep_t)
		return (ft_error("Arguments must be positif numbers.") + 1);
	d.p = malloc(sizeof(t_philo) * d.nb);
	if (d.p == NULL)
		return (ft_error("Malloc failed.") + 1);
	if (init(&d) == 1)
	{
		free(d.p);
		return (1);
	}
	if (launcher(&d) == 1)
	{
		exit_launcher(&d);
		return (1);
	}
	return (0);
}
