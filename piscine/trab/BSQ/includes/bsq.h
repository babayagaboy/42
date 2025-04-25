/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:38:59 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/12 21:31:57 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 8192

typedef struct s_data
{
	int		size_matrix_x;
	int		size_matrix_y;
	char	empty;
	char	obst;
	char	full;
}		t_data;

typedef struct s_square
{
	int	size;
	int	row;
	int	col;
}		t_square;

void	ft_putstr(char *str, int fd);
int		ft_isprintable(char c);
void	print_matrix(char **matrix, t_data *data);
void	free_matrix(char **matrix, t_data *data);
int		min3(int a, int b, int c);

int		validate_chars(t_data *data);
int		parse_number(char *str, int len);
int		extract_header_info(char *buffer, int len, t_data *data);
int		read_header(int fd, t_data *data);
int		validate_line(char *line, int len, t_data *data);

char	**alloc_matrix_rows(int rows);
int		alloc_matrix_cols(char **matrix, int rows, int cols);
char	**alloc_matrix(t_data *data);
int		read_map_line(int fd, char *line, int *len);
void	copy_line_to_matrix(char **matrix, char *line, int row, int len);

char	**read_first_line(int fd, t_data *data, char *line);
char	**read_map(int fd, t_data *data);

int		**alloc_dp_matrix(int rows, int cols);
void	free_dp_matrix(int **dp, int rows);
void	update_max_square(int value, int i, int j, t_square *max);
void	fill_dp_cell(int **dp, char **matrix, t_data *data, t_square *max);
void	mark_square(char **matrix, t_data *data, t_square *max);
void	solve(char **matrix, t_data *data);

int		copy_stdin_to_file(void);
int		process_map_fd(int fd);
int		process_stdin(void);
int		process_file(char *filename);
int		main(int argc, char *argv[]);

#endif
