/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:10:52 by hgutterr          #+#    #+#             */
/*   Updated: 2025/11/17 17:10:52 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	print_usage(void)
{
    printf("Usage: ./philo num_philos time_to_die time_to_eat time_to_sleep [num_meals]\n");
}

static int	initialize_simulation(int argc, char **argv, t_data *data)
{
    memset(data, 0, sizeof(*data));
    if (init_data(argc, argv, data) != 0)
    {
        ft_printf("Error: initialization failed\n");
        return (1);
    }
    return (0);
}

static void	join_threads(t_data *data)
{
    int	i;

    i = 0;
    while (i < data->num_philos)
        pthread_join(data->philos[i++].thread, NULL);
    pthread_join(data->monitor, NULL);
}

static void	cleanup(t_data *data)
{
    int i;

    i = 0;
    while (i < data->num_philos)
        pthread_mutex_destroy(&data->forks[i++]);
    pthread_mutex_destroy(&data->data_mutex);
    pthread_mutex_destroy(&data->print_mutex);
    free(data->forks);
    free(data->philos);
}

int	main(int argc, char **argv)
{
    t_data	data;

    if (argc < 5 || argc > 6)
    {
        print_usage();
        return (1);
    }
    if (initialize_simulation(argc, argv, &data) != 0)
        return (1);
    join_threads(&data);
    cleanup(&data);
    return (0);
}
