/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:06:37 by alebross          #+#    #+#             */
/*   Updated: 2021/12/14 19:06:39 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_launcher(t_data *d)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = d->p;
	while (i < d->nb)
	{
		pthread_join(p[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < d->nb)
	{
		pthread_mutex_destroy(&p[i].lf);
		i++;
	}
	free(d->p);
	pthread_mutex_destroy(&d->pen);
	pthread_mutex_destroy(&d->data);
}
