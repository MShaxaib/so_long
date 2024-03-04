/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:50:47 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/03 23:31:00 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_controller(t_so_long *stack, char dir)
{
	find_player(stack);
	printf("X: %d, Y: %d\n", stack->player->pos_x,stack->player->pos_y);
	//check if wall || coin || exit

	if (dir == 'U') //& UP
	{
		if(stack->level->level[stack->player->pos_y - 1][stack->player->pos_x] == '1')
			return;
		if(stack->level->level[stack->player->pos_y - 1][stack->player->pos_x] == 'C')
			stack->level->coins++;			
		stack->level->level[stack->player->pos_y - 1][stack->player->pos_x] = 'P';
		mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
		stack->data->img_player, stack->player->pos_x * 64 ,\
		(stack->player->pos_y - 1) * 64);
	}
	else if (dir == 'D') //^ Down
	{
		if(stack->level->level[stack->player->pos_y + 1][stack->player->pos_x] == '1')
			return;
		if(stack->level->level[stack->player->pos_y + 1][stack->player->pos_x] == 'C')
			stack->level->coins++;
		stack->level->level[stack->player->pos_y + 1][stack->player->pos_x] = 'P';
		mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
		stack->data->img_player, stack->player->pos_x * 64 ,\
		(stack->player->pos_y + 1) * 64);
	}
	else if (dir == 'L') //! left
	{
		if(stack->level->level[stack->player->pos_y][stack->player->pos_x - 1] == '1')
			return;
		if(stack->level->level[stack->player->pos_y][stack->player->pos_x - 1] == 'C')
			stack->level->coins++;	
		stack->level->level[stack->player->pos_y][stack->player->pos_x - 1] = 'P';
		mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
		stack->data->img_player, (stack->player->pos_x - 1) * 64 ,\
		stack->player->pos_y * 64);
	}
	else if (dir == 'R') //* Right
	{
		if(stack->level->level[stack->player->pos_y][stack->player->pos_x + 1] == '1')
			return;
		if(stack->level->level[stack->player->pos_y - 1][stack->player->pos_x + 1] == 'C')
			stack->level->coins++;	
		stack->level->level[stack->player->pos_y][stack->player->pos_x + 1] = 'P';
		mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
		stack->data->img_player, (stack->player->pos_x + 1) * 64 ,\
		stack->player->pos_y * 64);
	}
	stack->level->level[stack->player->pos_y ][stack->player->pos_x] = '0';
	mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win,\
	stack->data->background, stack->player->pos_x * 64 ,\
	stack->player->pos_y * 64);
}
