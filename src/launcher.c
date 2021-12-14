/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:06:44 by alebross          #+#    #+#             */
/*   Updated: 2021/12/14 19:47:26 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleeping(long long time, t_data *d)
{
	long long	i;

	i = actual_time();
	pthread_mutex_lock(&d->data);
	while ((!((actual_time() - i) >= time)) && d->alive)
	{
		pthread_mutex_unlock(&d->data);
		usleep(50);
		pthread_mutex_lock(&d->data);
	}
	pthread_mutex_unlock(&d->data);
}

static void	eating(t_philo *p)
{
	t_data	*d;

	d = p->ds;
	pthread_mutex_lock(&p->lf);
	pthread_mutex_lock(&d->data);
	print_status(p->id, "has taken a fork.", d);
	pthread_mutex_unlock(&d->data);
	if (!p->rf)
	{
		pthread_mutex_unlock(&p->lf);
		ft_usleep(d->die_t * 2);
		return ;
	}
	pthread_mutex_lock(p->rf);
	pthread_mutex_lock(&d->data);
	print_status(p->id, "has taken a fork.", d);
	print_status(p->id, "\033[0;32mis eating.", d);
	p->last_eat = actual_time();
	pthread_mutex_unlock(&d->data);
	sleeping(d->eat_t, d);
	pthread_mutex_lock(&d->data);
	p->eat_count++;
	pthread_mutex_unlock(&d->data);
	pthread_mutex_unlock(&p->lf);
	pthread_mutex_unlock(p->rf);
}

static void	*life(void *arg)
{
	t_philo	*p;
	t_data	*d;

	p = (t_philo *)arg;
	d = p->ds;
	if (!p->id % 2)
		usleep(1500);
	pthread_mutex_lock(&p->ds->data);
	while (d->alive && !d->finish)
	{
		pthread_mutex_unlock(&d->data);
		eating(p);
		pthread_mutex_lock(&d->data);
		print_status(p->id, "is sleeping.", d);
		pthread_mutex_unlock(&d->data);
		sleeping(d->sleep_t, d);
		pthread_mutex_lock(&d->data);
		print_status(p->id, "is thinking.", d);
	}
	pthread_mutex_unlock(&d->data);
	return (NULL);
}

static void	*life2(void *arg)
{
	t_philo	*p;
	t_data	*d;

	p = (t_philo *)arg;
	d = p->ds;
	if (!p->id % 2)
		usleep(1500);
	pthread_mutex_lock(&p->ds->data);
	while (d->alive && !d->finish && p->eat_count < d->eat_nb)
	{
		pthread_mutex_unlock(&d->data);
		eating(p);
		pthread_mutex_lock(&d->data);
		print_status(p->id, "is sleeping.", d);
		pthread_mutex_unlock(&d->data);
		sleeping(d->sleep_t, d);
		pthread_mutex_lock(&d->data);
		print_status(p->id, "is thinking.", d);
	}
	pthread_mutex_unlock(&d->data);
	return (NULL);
}

int	launcher(t_data *d)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = d->p;
	while (i < d->nb)
	{
		if (d->eat_nb == -1 && pthread_create(&d->p[i].thread, NULL,
				life, &d->p[i]) != 0)
			return (ft_error("pthread_create failed.") + 1);
		if (d->eat_nb != -1 && pthread_create(&d->p[i].thread, NULL,
				life2, &d->p[i]) != 0)
			return (ft_error("pthread_create failed.") + 1);
		i++;
	}
	check_end(d, p);
	exit_launcher(d);
	return (0);
}
