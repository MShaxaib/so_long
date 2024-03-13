/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:27:15 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/13 19:05:32 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//! Add checks for each malloc
void	init_level_stack(t_so_long *stack)
{
	stack->level = malloc (sizeof(t_level));
	stack->data = malloc (sizeof(t_data));
	stack->player = malloc (sizeof(t_player));
	stack->exit = malloc (sizeof(t_exit));
	stack->enemy = malloc (sizeof(t_enemy));
	stack->level->coins_collected = 0;
	stack->level->rows = 1;
	stack->level->moves = 1;
	stack->enemy->ctr = 0;
	stack->enemy->fps = 30;
	stack->data->anim_fps = 70;
	stack->enemy->flag = 0;
}

void	print_text(t_so_long *stack)
{
	stack->data->black = mlx_new_image(stack->data->mlx, 1000, 328);
	mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, \
	stack->data->black, (stack->level->column - 14) * 64, \
	(stack->level->rows) * 64);
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 12.8) * 64, stack->level->rows * 64, \
	0x00FFCCFF, "Number of moves:");
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 10.3) * 64, stack->level->rows * 64, \
	0x00FFCCFF, ft_itoa(stack->level->moves));
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 3.5) * 64, stack->level->rows * 64, \
	0x00FFCCFF, "Coins Collected:  /");
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 0.9) * 64, stack->level->rows * 64, \
	0x00FFCCFF, ft_itoa(stack->level->coins_collected));
	mlx_string_put(stack->data->mlx, stack->data->mlx_win, \
	(stack->level->column - 0.5) * 64, stack->level->rows * 64, \
	0x00FFCCFF, ft_itoa(stack->level->coins));
	mlx_destroy_image(stack->data->mlx, stack->data->black);
}
