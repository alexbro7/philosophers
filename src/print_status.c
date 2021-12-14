#include "philo.h"

void	print_status(unsigned int id, char *str, t_data *d)
{
	pthread_mutex_lock(&d->pen);
	if (d->alive && !d->finish)
		printf("%ld\t\tPhilo %u %s\n", actual_time() - d->start, id, str); 
	pthread_mutex_unlock(&d->pen);
}
