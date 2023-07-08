#include "so_long.h"

static mlx_image_t* image;
static mlx_image_t* dolph_img0;
static mlx_image_t* dolph_img1;
int pressed;

// -----------------------------------------------------------------------------

int32_t get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// Exit the program as failure.
void ft_error(void)
{
	//fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	ft_move(mlx_t *mlx, mlx_image_t *dolph)
{
	int	dist = 64;

	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		if (pressed != 1)
		{
			pressed = 1;
			dolph->instances[0].y += dist;
		}
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		if (pressed != 1)
		{
			pressed = 1;
			dolph->instances[0].y -= dist;
		}
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		if (pressed != 1)
		{
			pressed = 1;
			dolph->instances[0].x -= dist;
		}
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		if (pressed != 1)
		{
			pressed = 1;
			dolph->instances[0].x += dist;
		}
	}
	else if (pressed)
		pressed = 0;
}

void ft_animate(void* param)
{
	static int	count;
	int	nFrames = 6;
	//mlx_texture_t* dolph_tex;

	count++;
	if (count == nFrames)
	{
		//dolph_tex = mlx_load_png("./assets/dolph0.png");
		dolph_img1->instances[0].x = dolph_img0->instances[0].x;
		dolph_img1->instances[0].y = dolph_img0->instances[0].y;
		dolph_img0->instances[0].x = -256;
		dolph_img0->instances[0].y = -256;

		ft_move(param, dolph_img1);
	}
	else if (count >= nFrames * 2)
	{
		dolph_img0->instances[0].x = dolph_img1->instances[0].x;
		dolph_img0->instances[0].y = dolph_img1->instances[0].y;
		dolph_img1->instances[0].x = -256;
		dolph_img1->instances[0].y = -256;
		count = 0;

		ft_move(param, dolph_img0);
	}

}


// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t			*mlx;

	(void)argc;
	(void)argv;

	mlx_set_setting(MLX_MAXIMIZED, true);

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Dolphinstein 2D", true)))
		ft_error();
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		ft_error();
	}

	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		ft_error();
	}

	mlx_texture_t* dolph_tex0 = mlx_load_png("./assets/dolph.png");
	if (!dolph_tex0)
		ft_error();
	dolph_img0 = mlx_texture_to_image(mlx, dolph_tex0);
	if (!dolph_img0)
		ft_error();
	if (mlx_image_to_window(mlx, dolph_img0, 0, 0) < 0)
		ft_error();

	mlx_texture_t* dolph_tex1 = mlx_load_png("./assets/dolph0.png");
	if (!dolph_tex1)
		ft_error();
	dolph_img1 = mlx_texture_to_image(mlx, dolph_tex1);
	if (!dolph_img1)
		ft_error();
	if (mlx_image_to_window(mlx, dolph_img1, -256, -256) < 0)
		ft_error();

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop_hook(mlx, ft_animate, mlx);

	read_map(mlx, dolph_img0);
	
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}