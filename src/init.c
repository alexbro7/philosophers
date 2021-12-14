#include "philo.h"

static int	init2(t_data *d, int i)
{
	while (i < d->nb)
	{
		d->p[i].id = i + 1;
		d->p[i].eat_count = 0;
		d->p[i].last_eat = d->start;
		d->p[i].ds = d;
		if (pthread_mutex_init(&d->p[i].lf, NULL) == 1)
			return (ft_error("pthread_mutex_init failed.") + 1);
		if (d->nb == 1)
		{
			d->p[i].rf = NULL;
			return (0);
		}
		if (i == d->nb - 1)
			d->p[i].rf = &d->p[0].lf;
		else
			d->p[i].rf = &d->p[i + 1].lf;
		i++;
	}
	return (0);
}

int		init(t_data *d)
{
	int	i;

	i = 0;
	d->alive = 1;
	d->finish = 0;
	if (pthread_mutex_init(&d->pen, NULL) == 1)
		return (ft_error("pthread_mutex_init failed.") + 1);
	if (pthread_mutex_init(&d->data, NULL) == 1)
		return (ft_error("pthread_mutex_init failed.") + 1);
	d->start = actual_time();
	if (d->start == -1)
		return (ft_error("gettimeofday failed.") + 1);
	return (init2(d, i));
}
