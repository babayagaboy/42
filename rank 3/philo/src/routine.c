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

static int	eat_forks_even(t_philo *ph, t_data *data)
{
	if (someone_died(data))
		return (0);
	pthread_mutex_lock(&data->forks[ph->right_fork]);
	if (someone_died(data))
	{
		pthread_mutex_unlock(&data->forks[ph->right_fork]);
		return (0);
	}
	print_action(ph, "has taken a fork");
	pthread_mutex_lock(&data->forks[ph->left_fork]);
	if (someone_died(data))
	{
		pthread_mutex_unlock(&data->forks[ph->left_fork]);
		pthread_mutex_unlock(&data->forks[ph->right_fork]);
		return (0);
	}
	print_action(ph, "has taken a fork");
	return (1);
}

static int	eat_forks_odd(t_philo *ph, t_data *data)
{
	if (someone_died(data))
		return (0);
	pthread_mutex_lock(&data->forks[ph->left_fork]);
	if (someone_died(data))
	{
		pthread_mutex_unlock(&data->forks[ph->left_fork]);
		return (0);
	}
	print_action(ph, "has taken a fork");
	pthread_mutex_lock(&data->forks[ph->right_fork]);
	if (someone_died(data))
	{
		pthread_mutex_unlock(&data->forks[ph->right_fork]);
		pthread_mutex_unlock(&data->forks[ph->left_fork]);
		return (0);
	}
	print_action(ph, "has taken a fork");
	return (1);
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
	if (data->num_philos == 1)
	{
		pthread_mutex_unlock(&data->data_mutex);
		print_action(ph, "has taken a fork");
		precise_sleep(ph, data->time_to_die);
		return (NULL);
	}
	pthread_mutex_unlock(&data->data_mutex);
	if ((ph->id % 2) == 0)
		precise_sleep(ph, 15);
	while (!someone_died(data) && (data->num_meals == -1
			|| ph->meals_eaten < data->num_meals))
	{
		if (ph->left_fork < ph->right_fork)
		{
			if (!eat_forks_odd(ph, data))
				break ;
		}
		else
		{
			if (!eat_forks_even(ph, data))
				break ;
		}
		eat_and_sleep(ph, data);
	}
	return (NULL);
}
