/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:40:00 by hgutterr          #+#    #+#             */
/*   Updated: 2026/01/22 15:40:00 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	eat_forks_even(t_philo *ph, t_data *data)
{
	if (!someone_died(data))
		pthread_mutex_lock(&data->forks[ph->right_fork]);
	else
		return ;
	print_action(ph, "has taken a fork");
	if (!someone_died(data))
		pthread_mutex_lock(&data->forks[ph->left_fork]);
	else
	{
		pthread_mutex_unlock(&data->forks[ph->right_fork]);
		return ;
	}
	print_action(ph, "has taken a fork");
}

static void	eat_forks_odd(t_philo *ph, t_data *data)
{
	if (!someone_died(data))
		pthread_mutex_lock(&data->forks[ph->left_fork]);
	else
		return ;
	print_action(ph, "has taken a fork");
	if (!someone_died(data))
		pthread_mutex_lock(&data->forks[ph->right_fork]);
	else
	{
		pthread_mutex_unlock(&data->forks[ph->left_fork]);
		return ;
	}
	print_action(ph, "has taken a fork");
}

static void	eat_and_sleep(t_philo *ph, t_data *data)
{
	pthread_mutex_lock(&data->data_mutex);
	ph->last_meal_time = get_time_in_ms();
	pthread_mutex_unlock(&data->data_mutex);
	print_action(ph, "is eating");
	precise_sleep(ph, data->time_to_eat);
	pthread_mutex_lock(&data->data_mutex);
	ph->meals_eaten++;
	pthread_mutex_unlock(&data->data_mutex);
	pthread_mutex_unlock(&data->forks[ph->left_fork]);
	pthread_mutex_unlock(&data->forks[ph->right_fork]);
	if (data->num_meals > 0)
	{
		pthread_mutex_lock(&data->data_mutex);
		if (ph->meals_eaten >= data->num_meals)
		{
			pthread_mutex_unlock(&data->data_mutex);
			return ;
		}
		pthread_mutex_unlock(&data->data_mutex);
	}
	if (!someone_died(data))
		philo_sleep(ph, data);
}

void	*philo_routine(void *arg)
{
	t_philo	*ph;
	t_data	*data;

	ph = (t_philo *)arg;
	data = ph->data;
	pthread_mutex_lock(&data->data_mutex);
	ph->last_meal_time = get_time_in_ms();
	pthread_mutex_unlock(&data->data_mutex);
	if ((ph->id % 2) == 0)
		usleep(200);
	// prob with mutex of data when someones dies
	while (!someone_died(data) && (data->num_meals == -1
			|| ph->meals_eaten <= data->num_meals))
	{
		if ((ph->id % 2) == 0)
			eat_forks_even(ph, data);
		else
			eat_forks_odd(ph, data);
		if (someone_died(data))
			break ;
		eat_and_sleep(ph, data);
	}
	return (NULL);
}
