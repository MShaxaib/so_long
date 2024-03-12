/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:40:19 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/03/10 16:00:1 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_enemy(t_so_long *stack)
{
	if (stack->data->anim_fps >= 35)
		stack->data->img_enemy = mlx_xpm_file_to_image(stack->data->mlx, \
		"imgs/xpm/gengar-frame-0.xpm", &stack->data->w, &stack->data->h);
	if (stack->data->anim_fps < 35)
		stack->data->img_enemy = mlx_xpm_file_to_image(stack->data->mlx, \
		"imgs/xpm/gengar-frame-1.xpm", &stack->data->w, &stack->data->h);
	stack->data->anim_fps--;
}

void	checknmove(t_so_long *sl, int ctr, int oldx, int oldy)
{
	if (sl->level->level[oldy][oldx + 1] == '1' \
	|| sl->level->level[oldy][oldx + 1] == 'C' \
	|| sl->level->level[oldy][oldx + 1] == 'E')
		sl->enemy->flag[ctr] = 0;
	if (sl->enemy->flag[ctr] == 0)
	{
		if (sl->level->level[oldy][oldx - 1] == '0' \
		|| sl->level->level[oldy][oldx - 1] == 'P')
		{
			if (sl->level->level[oldy][oldx - 1] == 'P')
				exitandfree(sl, 1);
			sl->level->level[oldy][oldx] = '0';
			sl->level->level[sl->enemy->pos_y \
			[ctr]][sl->enemy->pos_x[ctr] - 1] = 'M';
		}
		if (sl->level->level[oldy][oldx - 1] == '1' \
		|| sl->level->level[oldy][oldx - 1] == 'C' \
		|| sl->level->level[oldy][oldx - 1] == 'E')
			sl->enemy->flag[ctr] = 1;
	}
	if (sl->enemy->flag[ctr] == 1)
	{
		if (sl->level->level[oldy][oldx + 1] == '0' \
		|| sl->level->level[oldy][oldx + 1] == 'P')
		{
			if (sl->level->level[oldy][oldx + 1] == 'P')
				exitandfree(sl, 0);
			sl->level->level[oldy][oldx] = '0';
			sl->level->level[sl->enemy->pos_y \
			[ctr]][sl->enemy->pos_x[ctr] + 1] = 'M';
		}
	}
}

void	find_enemy(t_so_long *stack, int counter)
{
	int	i;
	int	j;
	int	enemy_number;

	enemy_number = 0;
	i = 0;
	while (i < stack->level->rows)
	{
		j = 0;
		while (j < stack->level->column)
		{
			if (stack->level->level[i][j] == 'M')
				enemy_number++;
			if (enemy_number == counter)
			{
				stack->enemy->pos_y[counter - 1] = i;
				stack->enemy->pos_x[counter - 1] = j;
				break ;
			}
			j++;
		}
		if (enemy_number == counter)
			break ;
		i++;
	}
	if (!enemy_number)
		printf("Enemies not found\n");
}

void	move_enemy(t_so_long *sl, int ctr)
{
	int	oldx;
	int	oldy;

	find_enemy (sl, ctr + 1);
	oldx = sl->enemy->pos_x[ctr];
	oldy = sl->enemy->pos_y[ctr];
	if (sl->enemy->ctr != 0)
		if (sl->enemy->fps == 1)
			checknmove(sl, ctr, oldx, oldy);
}
