#include "philo.h"

void	exit_launcher(t_data *d)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = d->p;
	if (d->nb == 1)
		pthread_mutex_unlock(&p[0].lf);
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
