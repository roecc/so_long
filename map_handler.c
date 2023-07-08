#include "so_long.h"

void	read_map(mlx_t *mlx, mlx_image_t *dolph)
{
	int		fd;
	char	*line;
	int		len;
	int		tex_size;

	int	x;
	int	y;

	mlx_texture_t*  wall_tex = mlx_load_png("./assets/wall.png");
	if (!wall_tex)
		ft_error();
	mlx_image_t* wall = mlx_texture_to_image(mlx, wall_tex);
	if (!wall)
		ft_error();

	mlx_texture_t*  fish_tex = mlx_load_png("./assets/fish.png");
	if (!fish_tex)
		ft_error();
	mlx_image_t* fish = mlx_texture_to_image(mlx, fish_tex);
	if (!fish)
		ft_error();

	fd = open("map1.ber", O_RDONLY);
	/* line = get_next_line(fd);
	ft_printf("%s", line);
	len = ft_strlen(line); */

	len = -1;
	tex_size = 64;
	x = 0;
	y = 0;
	while ((line = get_next_line(fd)))
	{
		if(len == -1)
			len = ft_strlen(line);
		ft_printf("%s", line);
		if (ft_strlen(line) != len && line)
			ft_printf("\nERROR\n");
		x = -1;
		while (line[++x])
		{
			if (line[x] == '1')
				if (mlx_image_to_window(mlx, wall, tex_size * x, tex_size * y) < 0)
					ft_error();
			if (line[x] == 'C')
				if (mlx_image_to_window(mlx, fish, tex_size * x, tex_size * y) < 0)
					ft_error();
			if (line[x] == 'P')
			{
				dolph->instances[0].x = tex_size * x;
				dolph->instances[0].y = tex_size * y;
			}
		}
		y++;
	}
	ft_printf("\n");
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
