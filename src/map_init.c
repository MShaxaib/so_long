/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:03:22 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/13 18:02:43 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_long *stack)
{
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
	return (0);
}

void	drawtiles(t_so_long *sl, int i, int j)
{
	mlx_put_image_to_window(sl->data->mlx, \
	sl->data->mlx_win, sl->data->background, j * 64, i * 64);
	if (sl->level->level[i][j] == '1')
		mlx_put_image_to_window(sl->data->mlx, \
		sl->data->mlx_win, sl->data->img_wall, j * 64, i * 64);
	else if (sl->level->level[i][j] == 'P')
		mlx_put_image_to_window(sl->data->mlx, \
		sl->data->mlx_win, sl->data->img_player, j * 64, i * 64);
	else if (sl->level->level[i][j] == 'E')
		mlx_put_image_to_window(sl->data->mlx, \
		sl->data->mlx_win, sl->data->img_exit, j * 64, i * 64);
	else if (sl->level->level[i][j] == 'C')
		mlx_put_image_to_window(sl->data->mlx, \
		sl->data->mlx_win, sl->data->img_coin, j * 64, i * 64);
	else if (sl->level->level[i][j] == 'M')
		mlx_put_image_to_window(sl->data->mlx, \
		sl->data->mlx_win, sl->data->img_enemy, j * 64, i * 64);
}

void	draw_level(t_so_long *sl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (sl->level->level[i] != NULL)
	{
		j = 0;
		while (sl->level->level[i][j] != '\n' && sl->level->level[i][j] != '\0')
		{
			drawtiles (sl, i, j);
			j++;
		}
		i++;
	}
}

int	update(t_so_long *stack)
{
	int	counter;

	counter = 0;
	if (stack->enemy->fps == 0)
		stack->enemy->fps = 30;
	if (stack->data->anim_fps == 0)
		stack->data->anim_fps = 70;
	if (stack->data->anim_c_fps == 0)
		stack->data->anim_c_fps = 30;
	while (counter < stack->enemy->ctr)
	{
		move_enemy(stack, counter);
		counter++;
	}
	stack->enemy->fps--;
	memset (stack->enemy->pos_x, 0, sizeof(int) * stack->enemy->ctr);
	memset (stack->enemy->pos_y, 0, sizeof(int) * stack->enemy->ctr);
	mlx_clear_window (stack->data->mlx, stack->data->mlx_win);
	anim_enemy (stack);
	print_text (stack);
	draw_level (stack);
	return (0);
}

void	level_init(t_so_long *stack)
{
	stack->data->mlx = mlx_init();
	stack->data->mlx_win = mlx_new_window(stack->data->mlx, \
	stack->level->column * 64, (stack->level->rows + 0.5) * 64, \
	"Pokemon - Pikachu wants to go home!!!!");
	if (!stack->data)
		exit (2);
	stack->data->img_wall = mlx_xpm_file_to_image(stack->data->mlx, \
	"imgs/xpm/grass.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_player = mlx_xpm_file_to_image(stack->data->mlx, \
	"imgs/xpm/pikachu.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_exit = mlx_xpm_file_to_image(stack->data->mlx, \
	"imgs/xpm/pokeball.xpm", &stack->data->w, &stack->data->h);
	stack->data->background = mlx_xpm_file_to_image(stack->data->mlx, \
	"imgs/xpm/back.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_coin = mlx_xpm_file_to_image(stack->data->mlx, \
	"imgs/xpm/onigiri.xpm", &stack->data->w, &stack->data->h);
	stack->data->img_enemy = mlx_xpm_file_to_image(stack->data->mlx, \
	"imgs/xpm/gengar-frame-0.xpm", &stack->data->w, &stack->data->h);
	stack->data->background_d = mlx_xpm_file_to_image(stack->data->mlx, \
	"imgs/xpm/grass-dirt.xpm", &stack->data->w, &stack->data->h);
	mlx_loop_hook(stack->data->mlx, &update, stack);
	mlx_hook(stack->data->mlx_win, 2, 0, key_hook, stack);
	mlx_loop(stack->data->mlx);
}
