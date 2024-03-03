/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:03:22 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/29 23:05:03 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
// {
// 	char	*dst;

// 	dst = data->addr + y * data->line_length + x * (data->bits_per_pixel / 8);
// 	*(unsigned int*)dst = color;
// }

int key_hook(int keycode, t_data *mlx)
{
	// if(keycode == 124)
	// {
	// 	mlx->i += 50;
	// 	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, mlx->i + 10, 0);
	// }
	// else if (keycode == 123)
	// {
	// 	mlx->i -= 50;
	// 	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, mlx->i + 10, 0);
	// }
	if (keycode == 53)
	{
		// mlx_destroy_image(mlx->mlx, mlx->img);
		// mlx_destroy_image(mlx->mlx, mlx->replacement);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	return(0);
}

void draw_level(t_data *t_data , t_level *level)
{
	int i = 0;
	int j = 0;

	while(level->level[i] != NULL)
	{
		j = 0;
		while(level->level[i][j] != '\n' && level->level[i][j] != '\0')
		{
			mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->background, j * 64 , i * 64);
			if(level->level[i][j] == '1')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_wall, j * 64 , i * 64);
			else if(level->level[i][j] == 'P')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_player, j * 64 , i * 64);
			else if(level->level[i][j] == 'E')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_exit, j * 64 , i * 64);
			else if(level->level[i][j] == 'C')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->background, j * 64 , i * 64);
			// else if(level->level[i][j] == '0')
			// {
			// 	mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->background, j * 64 , i * 64);
			// }
		j++;
		}
	i++;
	}
}

void	level_init(t_level *level)
{
	t_data	*mlx_data;

	mlx_data = malloc(sizeof(t_data));
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, level->column * 64, level->rows * 64, "Hello world!");
	if(!mlx_data)
		exit(2);
	mlx_data->img_wall = mlx_xpm_file_to_image(mlx_data->mlx, "imgs/grass.xpm", &mlx_data->w, &mlx_data->h);
	mlx_data->img_player = mlx_xpm_file_to_image(mlx_data->mlx, "imgs/gengar.xpm", &mlx_data->w, &mlx_data->h);
	mlx_data->img_exit = mlx_xpm_file_to_image(mlx_data->mlx, "imgs/pokeball.xpm", &mlx_data->w, &mlx_data->h);
	mlx_data->background = mlx_xpm_file_to_image(mlx_data->mlx, "imgs/back.xpm", &mlx_data->w, &mlx_data->h);
	draw_level(mlx_data, level);
	mlx_key_hook(mlx_data->mlx_win, key_hook, &mlx_data->img_wall);
	mlx_loop(mlx_data->mlx);
}
