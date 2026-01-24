/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:43:47 by hgutterr          #+#    #+#             */
/*   Updated: 2026/01/24 13:04:14 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_action(t_philo *philo, const char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	timestamp = get_time_in_ms() - philo->data->start_time;
	printf("%ld\t\t%d\t\t%s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	precise_sleep(t_philo *philo, long ms)
{
	long	start;

	start = get_time_in_ms();
	while (get_time_in_ms() - start < ms)
	{
		if (someone_died(philo->data))
			break ;
		usleep(200);
	}
}

void	philo_sleep(t_philo *philo, t_data *data)
{
	if (someone_died(data))
		return ;
	print_action(philo, "is sleeping");
	precise_sleep(philo, data->time_to_sleep);
}

int	someone_died(t_data *data)
{
	int	val;

	pthread_mutex_lock(&data->data_mutex);
	val = data->someone_died;
	pthread_mutex_unlock(&data->data_mutex);
	return (val);
}

void	set_someone_died(t_data *data)
{
	pthread_mutex_lock(&data->data_mutex);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->data_mutex);
}
