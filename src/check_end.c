/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:07:27 by alebross          #+#    #+#             */
/*   Updated: 2021/12/14 19:09:27 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_death(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb && d->alive)
	{
		pthread_mutex_lock(&d->data);
		if (actual_time() - d->p[i].last_eat > d->die_t)
		{
			print_status(d->p[i].id, "\033[0;31mis dead.\033[m", d);
			d->alive = 0;
		}
		pthread_mutex_unlock(&d->data);
		usleep(100);
		i++;
	}
}

void	check_end(t_data *d, t_philo *p)
{
	int		i;

	while (!d->finish)
	{
		check_death(d);
		if (!d->alive)
			break ;
		i = 0;
		pthread_mutex_lock(&d->data);
		while (d->eat_nb != -1 && i < d->nb && p[i].eat_count >= d->eat_nb)
			i++;
		if (i == d->nb)
			d->finish = 1;
		pthread_mutex_unlock(&d->data);
	}
}
