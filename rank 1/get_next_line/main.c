#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd);
		get_next_line(fd);
	}
}