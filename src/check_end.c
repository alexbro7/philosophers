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
			print_status(d->p[i].id, "is dead.", d);
			d->alive = 0;
		}
		pthread_mutex_unlock(&d->data);
		usleep(100);
	}
}

void	check_end(t_data *d, t_philo *p)
{
	int		i;

	while (!d->finish)
	{
		check_death(d);
		if (!d->alive)
			break;
		i = 0;
		pthread_mutex_lock(&d->data);
		while (d->eat_nb != -1 && i < d->nb && p[i].eat_count >= d->eat_nb)
			i++;
		if (i == d->nb)
			d->finish = 1;
		pthread_mutex_unlock(&d->data);
	}
}
