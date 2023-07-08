#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "libs/gnl/get_next_line.h"
#include "libs/libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

void	read_map()
{
	int	fd;
	char	*line;

	write(1, "hello there\n", 12);

	fd = open("map1.ber", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		ft_putstr_fd(line, 1);
	}
}

int	check_map(char *map)
{
	int	x;
	int	y;
	int	width;

	//x/y	01234  always < width
	//		56789

	x = -1;
	while(map[++x] != '\n')
		if (map[x] != '1')
			return (0);
	y = 1;
	width = x; 
	while (map[y * width + x])
	{
		x = -1;
		while (++x < width)
		{
			if (x == 0 || x == width - 1)
				if (map[y * width + x] != '1')
					return (0);
		}
		y++;
	}
	return (1);
	//if (x%width == 0 || x%width)
}
