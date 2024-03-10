/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:27:15 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/10 15:39:51 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_level_stack(t_so_long *stack)
{
	// checks
	
	stack->level = malloc(sizeof(t_level));
	stack->data = malloc(sizeof(t_data));
	stack->player = malloc(sizeof(t_player));
	stack->exit = malloc(sizeof(t_exit));
	stack->enemy = malloc(sizeof(t_enemy));
	stack->level->coins_collected = 0;
	stack->level->moves = 1;
	stack->enemy->ctr = 0	;
	stack->enemy->fps = 30;
	stack->data->anim_fps = 70;
	stack->enemy->flag = 0;
}