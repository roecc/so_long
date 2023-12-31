#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "libs/gnl/get_next_line.h"
#include "libs/libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512
/* 
typedef struct s_vect
{
	int				x;
	int				y;
}					t_vect;

typedef struct s_fish_lst
{
	int				loc[2];

	struct s_fish_lst	*next;
	struct s_fish_lst	*prev;
}					t_fish_lst;
*/
char	*read_map(mlx_t *mlx, mlx_image_t *dolph);
int	check_map(char *map);
void	collect_fish(int loc, char *map);

void ft_error(void);

