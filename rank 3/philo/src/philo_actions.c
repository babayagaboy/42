/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:43:47 by hgutterr          #+#    #+#             */
/*   Updated: 2025/12/03 10:43:47 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_action(t_philo *philo, const char *msg)
{
    long	timestamp;

    pthread_mutex_lock(&philo->data->print_mutex);
    timestamp = get_time_in_ms() - philo->data->start_time;
    printf("%ld		%d		%s\n", timestamp, philo->id, msg);
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
    while (!someone_died(data))
    {
        if ((ph->id % 2) == 0)
        {
            while (!someone_died(data) && pthread_mutex_trylock(&data->forks[ph->right_fork]) != 0)
                usleep(10);
            if (someone_died(data))
                break ;
            print_action(ph, "has taken a fork");
            while (!someone_died(data) && pthread_mutex_trylock(&data->forks[ph->left_fork]) != 0)
                usleep(10);
            if (someone_died(data))
            {
                pthread_mutex_unlock(&data->forks[ph->right_fork]);
                break ;
            }
            print_action(ph, "has taken a fork");
        }
        else
        {
            while (!someone_died(data) && pthread_mutex_trylock(&data->forks[ph->left_fork]) != 0)
                usleep(10);
            if (someone_died(data))
                break ;
            print_action(ph, "has taken a fork");
            while (!someone_died(data) && pthread_mutex_trylock(&data->forks[ph->right_fork]) != 0)
                usleep(10);
            if (someone_died(data))
            {
                pthread_mutex_unlock(&data->forks[ph->left_fork]);
                break ;
            }
            print_action(ph, "has taken a fork");
        }
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
        if (someone_died(data))
            break ;
        if (data->num_meals > 0)
        {
            pthread_mutex_lock(&data->data_mutex);
            if (ph->meals_eaten >= data->num_meals)
            {
                pthread_mutex_unlock(&data->data_mutex);
                break ;
            }
            pthread_mutex_unlock(&data->data_mutex);
        }
        print_action(ph, "is sleeping");
        precise_sleep(ph, data->time_to_sleep);
    }
    return (NULL);
}

void	*monitor_routine(void *arg)
{
    t_data	*data;
    int		i;
    long	now;
    int		all_full;

    data = (t_data *)arg;
    while (1)
    {
        i = 0;
        all_full = 1;
        while (i < data->num_philos)
        {
            pthread_mutex_lock(&data->data_mutex);
            now = get_time_in_ms();
            if ((now - data->philos[i].last_meal_time) > data->time_to_die)
            {
                print_action(&data->philos[i], "died");
                data->someone_died = 1;
                pthread_mutex_unlock(&data->data_mutex);
                return (NULL);
            }
            if (data->num_meals > 0 && data->philos[i].meals_eaten < data->num_meals)
                all_full = 0;
            pthread_mutex_unlock(&data->data_mutex);
            i++;
        }
        if (data->num_meals > 0 && all_full)
        {
            pthread_mutex_lock(&data->data_mutex);
            data->someone_died = 1;
            pthread_mutex_unlock(&data->data_mutex);
            return (NULL);
        }
        usleep(1000);
    }
    return (NULL);
}
