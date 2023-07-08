NAME = Dolphinstein

SOURCES = \
test.c \
map_handler.c

LIBFT_PATH = ./libs/libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_PATH)/lib$(LIBFT_NAME).a

MLX_PATH = ./MLX42/build
MLX_NAME = mlx42
MLX = $(MLX_PATH)/lib$(MLX_NAME).a

CC = cc
CFLAGS = -Wall -Wextra -Werror
 #LDFLAGS for linux 
 #LDFLAGS = -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(MLX_PATH) -l$(MLX_NAME) -lglfw -ldl -lm -pthread 
 #LDFLAGS for MacOS 
 #LDFLAGS = -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(MLX_PATH) -l$(MLX_NAME) -lglfw -ldl -lm -pthread -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" 

ifeq ($(shell uname), Linux)
 LDFLAGS = -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(MLX_PATH) -l$(MLX_NAME) -lglfw -ldl -lm -pthread
else
 LDFLAGS = -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(MLX_PATH) -l$(MLX_NAME) -lglfw -ldl -lm -pthread -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
endif

OBJECTS = $(SOURCES:.c=.o)

all: libmlx $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFT) $(MLX)

$(LIBFT): $(LIBFT_PATH)/*.c
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

libmlx:
	@if git submodule status | egrep -q '^[-]|^[+]' ; then \
		echo "INFO: Need to reinitialize git submodules"; \
		git submodule update --init; \
	fi
	@if [ ! -d "./MLX42/build" ]; then \
		cmake ./MLX42 -B ./MLX42/build ; \
	fi


%.o: %.c
	 $(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJECTS) 
	make -C $(LIBFT_PATH) clean 

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all clean

.PHONY: all clean fclean re libmlx

