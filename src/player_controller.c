/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:50:47 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/12 16:58:48 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_so_long *sl)
{
	if (sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] == '1')
		return (0);
	if (sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] == 'C')
		sl->level->coins_collected++;
	if (sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] == 'E')
	{
		if (sl->level->coins == sl->level->coins_collected)
		{
			exitandfree(sl, 1);
			return (0);
		}
	}
	if (sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] == 'M')
	{
		exitandfree(sl, 0);
		return (0);
	}
	sl->level->level[sl->player->pos_y - 1][sl->player->pos_x] = 'P';
	mlx_put_image_to_window(sl->data->mlx, sl->data->mlx_win, \
	sl->data->img_player, sl->player->pos_x * 64, \
	(sl->player->pos_y - 1) * 64);
	return (1);
}

int	move_down(t_so_long *sl)
{
	if (sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] == '1')
		return (0);
	if (sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] == 'C')
		sl->level->coins_collected++;
	if (sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] == 'E')
	{
		if (sl->level->coins == sl->level->coins_collected)
		{
			exitandfree(sl, 1);
		}
		return (0);
	}
	if (sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] == 'M')
	{
		exitandfree(sl, 0);
		return (0);
	}
	sl->level->level[sl->player->pos_y + 1][sl->player->pos_x] = 'P';
	mlx_put_image_to_window(sl->data->mlx, sl->data->mlx_win, \
	sl->data->img_player, sl->player->pos_x * 64, \
	(sl->player->pos_y + 1) * 64);
	return (1);
}

int	move_left(t_so_long *sl)
{
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] == '1')
		return (0);
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] == 'C')
		sl->level->coins_collected++;
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] == 'E')
	{
		if (sl->level->coins == sl->level->coins_collected)
		{
			exitandfree(sl, 1);
		}
		return (0);
	}
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] == 'M')
	{
		exitandfree(sl, 0);
		return (0);
	}
	sl->level->level[sl->player->pos_y][sl->player->pos_x - 1] = 'P';
	mlx_put_image_to_window(sl->data->mlx, sl->data->mlx_win, \
	sl->data->img_player, (sl->player->pos_x - 1) * 64, \
	sl->player->pos_y * 64);
	return (1);
}

int	move_right(t_so_long *sl)
{
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] == '1')
		return (0);
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] == 'C')
		sl->level->coins_collected++;
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] == 'E')
	{
		if (sl->level->coins == sl->level->coins_collected)
		{
			exitandfree(sl, 1);
		}
		return (0);
	}
	if (sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] == 'M')
	{
		exitandfree(sl, 0);
		return (0);
	}
	sl->level->level[sl->player->pos_y][sl->player->pos_x + 1] = 'P';
	mlx_put_image_to_window(sl->data->mlx, sl->data->mlx_win, \
	sl->data->img_player, (sl->player->pos_x + 1) * 64, \
	sl->player->pos_y * 64);
	return (1);
}

void	put_zero(t_so_long *stack)
{
	stack->level->moves++;
	stack->level->level[stack->player->pos_y][stack->player->pos_x] = '0';
	mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, \
	stack->data->background, stack->player->pos_x * 64, \
	stack->player->pos_y * 64);
}

void	player_controller(t_so_long *stack, char dir)
{
	find_player(stack);
	if (dir == 'U')
	{
		if (move_up(stack) == 1)
			put_zero(stack);
	}
	else if (dir == 'D')
	{
		if (move_down(stack) == 1)
			put_zero(stack);
	}
	else if (dir == 'L')
	{
		if (move_left(stack) == 1)
			put_zero(stack);
	}
	else if (dir == 'R')
	{
		if (move_right(stack) == 1)
			put_zero(stack);
	}
}
