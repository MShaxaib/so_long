/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:50:47 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/11 08:57:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_so_long *sl)
{
	if (sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] == '1')
		return ;
	if (sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] == 'C')
		sl->level->coins_collected++;
	if (sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] == 'E')
	{
		if (sl->level->coins == sl->level->coins_collected)
		{
			printf("<--------YOU WIN-------->\n");
			exitandfree(sl);
			return ;
		}
	}
	if (sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] == 'M')
	{
		printf("<--------YOU DED-------->\n");
		exitandfree(sl);
		return ;
	}
	sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] = 'P';
	mlx_put_image_to_window(sl->data->mlx, sl->data->mlx_win, \
	sl->data->img_player, sl->player->pos_x * 64, \
	(sl->player->pos_y - 1) * 64);
}

void	move_down(t_so_long *sl)
{
	if (sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] == '1')
		return ;
	if (sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] == 'C')
		sl->level->coins_collected++;
	if (sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] == 'E')
	{
		if (sl->level->coins == sl->level->coins_collected)
		{
			printf("<--------YOU WIN-------->\n");
			exitandfree(sl);
		}
		return ;
	}
	if (sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] == 'M')
	{
		printf("<--------YOU DED-------->\n");
		exitandfree(sl);
		return ;
	}
	sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] = 'P';
	mlx_put_image_to_window(sl->data->mlx, sl->data->mlx_win, \
	sl->data->img_player, sl->player->pos_x * 64, \
	(sl->player->pos_y + 1) * 64);
}

void	move_left(t_so_long *sl)
{
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] == '1')
		return ;
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] == 'C')
		sl->level->coins_collected++;
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] == 'E')
	{
		if (sl->level->coins == sl->level->coins_collected)
		{
			printf("<--------YOU WIN-------->\n");
			exitandfree(sl);
		}
		return ;
	}
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] == 'M')
	{
		printf("<--------YOU DED-------->\n");
		exitandfree(sl);
		return ;
	}
	sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] = 'P';
	mlx_put_image_to_window(sl->data->mlx, sl->data->mlx_win, \
	sl->data->img_player, (sl->player->pos_x - 1) * 64, \
	sl->player->pos_y * 64);
}

void	move_right(t_so_long *sl)
{
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] == '1')
		return ;
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] == 'C')
		sl->level->coins_collected++;
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] == 'E')
	{
		if (sl->level->coins == sl->level->coins_collected)
		{
			printf("<--------YOU WIN-------->\n");
			exitandfree(sl);
		}
		return ;
	}
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] == 'M')
	{
		printf("<--------YOU DED-------->\n");
		exitandfree(sl);
		return ;
	}
	sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] = 'P';
	mlx_put_image_to_window(sl->data->mlx, sl->data->mlx_win, \
	sl->data->img_player, (sl->player->pos_x + 1) * 64, \
	sl->player->pos_y * 64);
}

void	player_controller(t_so_long *stack, char dir)
{
	find_player(stack);
	if (dir == 'U')
		move_up(stack);
	else if (dir == 'D')
		move_down(stack);
	else if (dir == 'L')
		move_left(stack);
	else if (dir == 'R')
		move_right(stack);
	stack->level->moves++;
	stack->level->level[stack->player->pos_y][stack->player->pos_x] = '0';
	mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, \
	stack->data->background, stack->player->pos_x * 64, \
	stack->player->pos_y * 64);
}
