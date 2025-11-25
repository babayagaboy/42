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

int	main(int argc, char **argv)
{
	int	i;
    t_data	data;

	i = 0;
    if (argc < 5 || argc > 6)
        return (printf("Usage: ./philo num_philos time_to_die time_to_eat time_to_sleep [num_meals]\n"), 1);
	memset(&data, 0, sizeof(t_data));
    if (init_data(argc, argv, &data) != 0)
        return (printf("Error: initialization failed\n"), 1);
    while (i < data.num_philos)
        pthread_join(data.philos[i++].thread, NULL);
    pthread_join(data.monitor, NULL);
    i = 0;
    while (i < data.num_philos)
        pthread_mutex_destroy(&data.forks[i++]);
    pthread_mutex_destroy(&data.data_mutex);
    pthread_mutex_destroy(&data.print_mutex);
    free(data.forks);
    free(data.philos);
    return (0);
}
