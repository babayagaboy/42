/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:48:37 by hgutterr          #+#    #+#             */
/*   Updated: 2025/11/25 17:48:37 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	init_mutexes(t_data *data)
{
    int	i;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
    if (!data->forks)
        return (1);
    i = 0;
    while (i < data->num_philos)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
            return (1);
        i++;
    }
    if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
        return (1);
    if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
        return (1);
    return (0);
}

static int	init_philos(t_data *data)
{
    int	i;

    data->philos = malloc(sizeof(t_philo) * data->num_philos);
    if (!data->philos)
        return (1);
    i = 0;
    while (i < data->num_philos)
    {
        data->philos[i].id = i + 1;
        data->philos[i].left_fork = i;
        data->philos[i].right_fork = (i + 1) % data->num_philos;
        data->philos[i].meals_eaten = 0;
        data->philos[i].last_meal_time = data->start_time;
        data->philos[i].data = data;
        i++;
    }
    return (0);
}

static int	create_threads(t_data *data)
{
    int	i;

    data->start_time = get_time_in_ms();
    i = 0;
    while (i < data->num_philos)
    {
        if (pthread_create(&data->philos[i].thread, NULL, 
            philo_routine, &data->philos[i]) != 0)
            return (1);
        i++;
    }
    if (pthread_create(&data->monitor, NULL, monitor_routine, data) != 0)
        return (1);
    return (0);
}

int	init_data(int argc, char **argv, t_data *data)
{
    if (argc < 5 || argc > 6)
        return (1);
    data->num_philos = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->num_meals = -1;
    if (argc == 6)
        data->num_meals = ft_atoi(argv[5]);
    data->someone_died = 0;
    if (data->num_philos <= 0 || data->time_to_die <= 0 
        || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
        return (1);
    if (init_mutexes(data) != 0)
        return (1);
    if (init_philos(data) != 0)
        return (1);
    if (create_threads(data) != 0)
        return (1);
    return (0);
}