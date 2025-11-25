/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:11:14 by hgutterr          #+#    #+#             */
/*   Updated: 2025/11/17 17:11:14 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

typedef struct s_philo
{
    int				id;
    int				left_fork;
    int				right_fork;
    long			last_meal_time;
    int				meals_eaten;
    pthread_t		thread;
    struct s_data	*data;
}	t_philo;

typedef struct s_data
{
    int				num_philos;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				num_meals;
    long			start_time;
    int				someone_died;
    pthread_mutex_t	*forks;
    pthread_mutex_t	data_mutex;
    pthread_mutex_t	print_mutex;
    t_philo			*philos;
    pthread_t		monitor;
}	t_data;

// utils.c
long	get_time_in_ms(void);
int		ft_atoi(const char *nptr);

// init.c
int		init_data(int argc, char **argv, t_data *data);

// philo routine (add these)
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);

#endif