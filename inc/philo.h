/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:15:55 by alebross          #+#    #+#             */
/*   Updated: 2021/12/14 14:29:25 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# include <stdio.h>

typedef struct	s_philo
{
	pthread_t	thread;
	pthread_mutex_t	lf;
	pthread_mutex_t	*rf;
	int		id;
	long int	last_eat;
	int		eat_count;
	int		finish;
	struct s_data	*ds;
}		t_philo;

typedef struct s_data
{
	int		nb;
	int		die_t;
	int		eat_t;
	int		sleep_t;
	int		eat_nb;
	long int	start;
	int		alive;
	int		finish;
	t_philo		*p;
	pthread_mutex_t	pen;
	pthread_mutex_t	data;
	pthread_mutex_t	eating;
}				t_data;

int				main(int ac, char **av);
int				check_arguments(int ac, char **av);
t_data			get_arguments(char **av, int ac);
int			ft_atoi(char *str);
int				ft_error(char *str);
void			ft_putstr_fd(char *str, int fd);
int				ft_strlen(char *str);
int			init(t_data *d);
long int		actual_time(void);
void			print_status(unsigned int id, char *str, t_data *d);
int			launcher(t_data *d);
void			ft_usleep(long int time_in_ms);
void			check_end(t_data *d, t_philo *p);
void			exit_launcher(t_data *d);

#endif
