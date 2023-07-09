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
 */
char	*read_map(mlx_t *mlx, mlx_image_t *dolph);
int	check_map(char *map);

void ft_error(void);

