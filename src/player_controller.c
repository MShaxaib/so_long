/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:50:47 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/05 09:17:08 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_controller(t_so_long *stack, char dir)
{
	find_player(stack);
	
	if (dir == 'U') 		//& UP
	{
		if(stack->level->level[stack->player->pos_y - 1][stack->player->pos_x] == '1')
			return;
		if(stack->level->level[stack->player->pos_y - 1][stack->player->pos_x] == 'C')
			stack->level->coins_collected++;
		if(stack->level->level[stack->player->pos_y - 1][stack->player->pos_x] == 'E')
		{
			if(stack->level->coins == stack->level->coins_collected)
			{
				printf("<--------YOU WIN-------->\n");
				mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
				mlx_destroy_window(stack->data->mlx, stack->data->mlx_win);
				exit(0);
			}
			return;
		}
		stack->level->moves++;
		stack->level->level[stack->player->pos_y - 1][stack->player->pos_x] = 'P';
		mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
		stack->data->img_player, stack->player->pos_x * 64 ,\
		(stack->player->pos_y - 1) * 64);
	}
	else if (dir == 'D')	//^ Down
	{
		if(stack->level->level[stack->player->pos_y + 1][stack->player->pos_x] == '1')
			return;
		if(stack->level->level[stack->player->pos_y + 1][stack->player->pos_x] == 'C')
			stack->level->coins_collected++;
		if(stack->level->level[stack->player->pos_y + 1][stack->player->pos_x] == 'E')
		{
			if(stack->level->coins == stack->level->coins_collected)
			{
				printf("<--------YOU WIN-------->\n");
				mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
				mlx_destroy_window(stack->data->mlx, stack->data->mlx_win);
				exit(0);
			}
			return;
		}
		stack->level->level[stack->player->pos_y + 1][stack->player->pos_x] = 'P';
		mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
		stack->data->img_player, stack->player->pos_x * 64 ,\
		(stack->player->pos_y + 1) * 64);
		stack->level->moves++;
	}
	else if (dir == 'L')	//! left
	{
		if(stack->level->level[stack->player->pos_y][stack->player->pos_x - 1] == '1')
			return;
		if(stack->level->level[stack->player->pos_y][stack->player->pos_x - 1] == 'C')
			stack->level->coins_collected++;
		if(stack->level->level[stack->player->pos_y][stack->player->pos_x - 1] == 'E')
		{
			if(stack->level->coins == stack->level->coins_collected)
			{
				printf("<--------YOU WIN-------->\n");
				mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
				mlx_destroy_window(stack->data->mlx, stack->data->mlx_win);
				exit(0);
			}
			return;
		}
		stack->level->level[stack->player->pos_y][stack->player->pos_x - 1] = 'P';
		mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
		stack->data->img_player, (stack->player->pos_x - 1) * 64 ,\
		stack->player->pos_y * 64);
		stack->level->moves++;
	}
	else if (dir == 'R')	//* Right
	{
		if(stack->level->level[stack->player->pos_y][stack->player->pos_x + 1] == '1')
			return;
		if(stack->level->level[stack->player->pos_y][stack->player->pos_x + 1] == 'C')
			stack->level->coins_collected++;
		if(stack->level->level[stack->player->pos_y][stack->player->pos_x + 1] == 'E')
		{
			if(stack->level->coins == stack->level->coins_collected)
			{
				printf("<--------YOU WIN-------->\n");
				mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
				mlx_destroy_window(stack->data->mlx, stack->data->mlx_win);
				exit(0);
			}
			return;
		}
		stack->level->level[stack->player->pos_y][stack->player->pos_x + 1] = 'P';
		mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
		stack->data->img_player, (stack->player->pos_x + 1) * 64 ,\
		stack->player->pos_y * 64);
		stack->level->moves++;
	}
	
	stack->level->level[stack->player->pos_y ][stack->player->pos_x] = '0';
	mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
	stack->data->background, stack->player->pos_x * 64 ,\
	stack->player->pos_y * 64);
}

