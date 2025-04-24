/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:47:24 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/24 16:47:25 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE = 1
# endif

char *get_next_line(int fd);

#endif