/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:52:19 by hgutterr          #+#    #+#             */
/*   Updated: 2025/07/03 00:52:19 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signum)
{
    if (signum == SIGUSR1)
        printf("Received SIGUSR1\n");
    else if (signum == SIGUSR2)
        printf("Received SIGUSR2\n");
}

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);

	printf("PID = %d\n", getpid());

	while(true)
		pause();

	return(EXIT_SUCCESS);
}