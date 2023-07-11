#include "so_long.h"

mlx_image_t* fish;

char	*read_map(mlx_t *mlx, mlx_image_t *dolph)
{
	int		fd;
	char	*line;
	char	*map;
	int		len;
	int		tex_size;

	int	x;
	int	y;
	
	map = (char *)malloc(sizeof(char) * 1);
	if (!map)
		return(NULL);
	map[0] = '\0';
	mlx_texture_t*  wall_tex = mlx_load_png("./assets/wall.png");
	if (!wall_tex)
		ft_error();
	mlx_image_t* wall = mlx_texture_to_image(mlx, wall_tex);
	if (!wall)
		ft_error();

	mlx_texture_t*  fish_tex = mlx_load_png("./assets/fish.png");
	if (!fish_tex)
		ft_error();
	//mlx_image_t* fish = mlx_texture_to_image(mlx, fish_tex);
	fish = mlx_texture_to_image(mlx, fish_tex);
	if (!fish)
		ft_error();

	fd = open("map2.ber", O_RDONLY);
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
		if (ft_strlen(line) != len)
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


		wall->instances[2].y = -100;
		if (!(map = str_join(map, line)))
			return(NULL);
	}
	//ft_printf("\n");
	ft_printf("%s", map);
	ft_printf("\n");
	return(map);
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

int	find_fish(int loc, char *map)
{
	int	i;
	int	nf;

	i = -1;
	nf = 0;
	while (++i < loc)
		if (map[i] == 'C')
			nf++;
	return (nf);
}

int	found_all(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
		if (map[i] == 'C')
			if (fish->instances[find_fish(i, map)].x != -256)
				return (0);
	return (1);
}

void	collect_fish(int loc, char *map)
{
	int	fn;

	fn = find_fish(loc, map);
	if (fish->instances[fn].x != -256)
	{
		fish->instances[find_fish(loc, map)].x = -256;
		fish->instances[find_fish(loc, map)].y = -256;
		ft_printf("FOUND FISH\n");
		if (found_all(map))
			ft_printf("\nFOUND ALL\n");
		else
			ft_printf("\nNOT ALL\n");
	}
	else
		ft_printf("FOUND ALREADY");
}
