/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:06:25 by alebross          #+#    #+#             */
/*   Updated: 2021/12/14 19:09:47 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(unsigned int id, char *str, t_data *d)
{
	pthread_mutex_lock(&d->pen);
	if (d->alive)
	{
		if (id % 2)
			printf("\033[0;36m");
		else
			printf("\033[0;33m");
		printf("%ldms\tPhilo:%u %s\033[m\n", actual_time() - d->start, id, str);
	}
	pthread_mutex_unlock(&d->pen);
}
