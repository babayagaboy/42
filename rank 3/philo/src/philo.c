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

parse_arguments(int argc, char **argv, t_data *data)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	else
		data->num_meals = -1;
	if(data->num_philos <= 0 || data->time_to_die < 0 || data->time_to_eat < 0 || 
	data->time_to_sleep < 0 || (argc == 6 && data->num_meals <= 0))
	{
		printf("Invalid arguments\n");
		exit(1);
	}
}

initialize_data()
{
	
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);

	t_data data;
	parse_arguments(argc, argv, &data);
	initialize_data(argc, argv, &data);
	return (0);
}