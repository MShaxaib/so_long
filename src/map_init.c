/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:03:22 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/05 19:19:52 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Key codes:

up 		= 126
down 	= 125
left	= 123
right	= 124
esc		= 53 

*/ 

int key_hook(int keycode, t_so_long *stack)
{
	stack->data->black = mlx_new_image(stack->data->mlx, 400,328);
	mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, stack->data->black, 0, 326);
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, 0, 326, 0x00FFCCFF, "Number of moves:");
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, 170, 326, 0x00FFCCFF, ft_itoa(stack->level->moves));
	printf("number of moves : %s\n", ft_itoa(stack->level->moves));
	if (keycode == 53)
	{
		mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
		mlx_destroy_window(stack->data->mlx, stack->data->mlx_win);
		exit(0);
	}
	else if (keycode == 126)
		player_controller(stack, 'U');
	else if (keycode == 125)
		player_controller(stack, 'D');
	else if (keycode == 124)
		player_controller(stack, 'R');
	else if (keycode == 123)
		player_controller(stack, 'L');	
	return(0);
}

void draw_level(t_so_long *stack)
{
	int i = 0;
	int j = 0;

	while(stack->level->level[i] != NULL)
	{
		j = 0;
		while(stack->level->level[i][j] != '\n' && stack->level->level[i][j] != '\0')
		{
			mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, stack->data->background, j * 64 , i * 64);
			if(stack->level->level[i][j] == '1')
				mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, stack->data->img_wall, j * 64 , i * 64);
			else if(stack->level->level[i][j] == 'P')
				mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, stack->data->img_player, j * 64 , i * 64);
			else if(stack->level->level[i][j] == 'E')
				mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, stack->data->img_exit, j * 64 , i * 64);
			else if(stack->level->level[i][j] == 'C')
				mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, stack->data->img_coin, j * 64 , i * 64);
		j++;
		}
	i++;
	}
}

void	level_init(t_so_long *stack)
{

	stack->data->mlx = mlx_init();
	stack->data->mlx_win = mlx_new_window(stack->data->mlx, stack->level->column * 64, (stack->level->rows + 0.5) * 64, "Pokemon - Midlife crisis pikachu wants to go home!");
	if(!stack->data)
		exit(2);
	stack->data->img_wall = mlx_xpm_file_to_image(stack->data->mlx, "imgs/grass.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_player = mlx_xpm_file_to_image(stack->data->mlx, "imgs/pikachu.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_exit = mlx_xpm_file_to_image(stack->data->mlx, "imgs/pokeball.xpm", &stack->data->w, &stack->data->h);
	stack->data->background = mlx_xpm_file_to_image(stack->data->mlx, "imgs/back.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_coin = mlx_xpm_file_to_image(stack->data->mlx, "imgs/onigiri.xpm", &stack->data->w, &stack->data->h);
	draw_level(stack);
	mlx_hook(stack->data->mlx_win, 2, 0, key_hook, stack);
	mlx_loop(stack->data->mlx);
}
