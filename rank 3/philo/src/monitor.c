/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:40:00 by hgutterr          #+#    #+#             */
/*   Updated: 2026/01/22 15:40:00 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_philosopher_death(t_data *data, int i)
{
	long	now;

	//pthread_mutex_lock(&data->data_mutex); // tirar para n ficar preso.
	now = get_time_in_ms();
	if ((now - data->philos[i].last_meal_time) > data->time_to_die)
	{
		print_action(&data->philos[i], "died");
		data->someone_died = 1;
		pthread_mutex_unlock(&data->data_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->data_mutex);
	return (0);
}

static int	check_all_full(t_data *data)
{
	int	i;
	int	all_full;

	i = 0;
	all_full = 1;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->data_mutex);
		if (data->num_meals > 0
			&& data->philos[i].meals_eaten < data->num_meals)
			all_full = 0;
		pthread_mutex_unlock(&data->data_mutex);
		i++;
	}
	if (all_full && data->num_meals > 0)
	{
		pthread_mutex_lock(&data->data_mutex);
		data->someone_died = 1;
		pthread_mutex_unlock(&data->data_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (check_philosopher_death(data, i))
				return (NULL);
			i++;
		}
		if (check_all_full(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
