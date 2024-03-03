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
	if(keycode == 124)
	{
		mlx->i += 50;
		// mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->replacement, 0, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, mlx->i + 10, 0);
	}
	else if (keycode == 123)
	{
		mlx->i -= 50;
		// mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->replacement, 0, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, mlx->i + 10, 0);
	}
	else if (keycode == 53)
	{
		// mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_image(mlx->mlx, mlx->replacement);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	return(0);
}

void	level_init()
{
	
	int		w;
	int 	h;

	
	t_data	img;

	img.i = 0;
	img.path = "imgs/pika.xpm";
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_xpm_file_to_image(img.mlx, img.path, &w, &h);
	img.replacement = mlx_new_image(img.mlx, 1920, 1080);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	// mlx_destroy_image(img.mlx, img.img);
	mlx_loop(img.mlx);
}

int main()
{
	level_init();
}