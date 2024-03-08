/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:03:22 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/08 17:46:27 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int update(t_so_long *stack)
{
	// (void)stack;
	if(stack->enemy->fps == 0)
		stack->enemy->fps = 20;
	move_enemy(stack);
	mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
	draw_level(stack);
	return(0);
}

void print_text(t_so_long *stack)
{
	stack->data->black = mlx_new_image(stack->data->mlx, 1000,328);
	mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
	stack->data->black, (stack->level->column - 14) * 64,\
	(stack->level->rows) * 64);
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 12.8) * 64, stack->level->rows * 64,\
	0x00FFCCFF, "Number of moves:");
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 10.3) * 64, stack->level->rows * 64,\
	0x00FFCCFF, ft_itoa(stack->level->moves));
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 3.5) * 64, stack->level->rows * 64,\
	0x00FFCCFF, "Coins Collected:  /");
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 0.9) * 64, stack->level->rows * 64, \
	0x00FFCCFF, ft_itoa(stack->level->coins_collected));
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 0.5) * 64, stack->level->rows * 64, \
	0x00FFCCFF, ft_itoa(stack->level->coins));
}

int key_hook(int keycode, t_so_long *stack)
{
	print_text(stack); //! its leaking probably : need to destroy stuff
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
			else if(stack->level->level[i][j] == 'M')
			{
				stack->enemy->ctr++;	
				mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, stack->data->img_enemy, j * 64 , i * 64);
			}
		j++;
		}
	i++;
	}
}

void	level_init(t_so_long *stack)
{

	stack->data->mlx = mlx_init();
	stack->data->mlx_win = mlx_new_window(stack->data->mlx, stack->level->column * 64, (stack->level->rows + 0.5) * 64, "Pokemon - Pikachu wants to go home!!!!");
	if(!stack->data)
		exit(2);
	stack->data->img_wall = mlx_xpm_file_to_image(stack->data->mlx, "imgs/grass.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_player = mlx_xpm_file_to_image(stack->data->mlx, "imgs/pikachu.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_exit = mlx_xpm_file_to_image(stack->data->mlx, "imgs/pokeball.xpm", &stack->data->w, &stack->data->h);
	stack->data->background = mlx_xpm_file_to_image(stack->data->mlx, "imgs/back.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_coin = mlx_xpm_file_to_image(stack->data->mlx, "imgs/onigiri.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_enemy = mlx_xpm_file_to_image(stack->data->mlx, "imgs/gengar.xpm", &stack->data->w, &stack->data->h);
	// draw_level(stack);
	mlx_loop_hook(stack->data->mlx, &update, stack);
	mlx_hook(stack->data->mlx_win, 2, 0, key_hook, stack);
	mlx_loop(stack->data->mlx);
}
