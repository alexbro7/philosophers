/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:29:21 by alebross          #+#    #+#             */
/*   Updated: 2021/12/14 14:29:50 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	test()
{
	long int start = actual_time();
	for (int i = 0; i < 10; i++)
	{
		usleep(1000);
		printf("%ld\n", actual_time() - start);
	}
	return (0);
}

int	main(int ac, char **av)
{
//	return (test());
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
	return (launcher(&d));
//	for (unsigned int i = 0; i < d.nb; i++)
//		printf("philo %d start %ld %u\n", d.p[i].id, d.p[i].last_eat, d.p[i].ds->die_t);
}
