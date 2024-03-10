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

void anim_enemy(t_so_long *stack)
{
	if(stack->data->anim_fps >= 35)
		stack->data->img_enemy = mlx_xpm_file_to_image(stack->data->mlx, "imgs/xpm/gengar-frame-0.xpm", &stack->data->w, &stack->data->h);
	if(stack->data->anim_fps < 35)
		stack->data->img_enemy = mlx_xpm_file_to_image(stack->data->mlx, "imgs/xpm/gengar-frame-1.xpm", &stack->data->w, &stack->data->h);
	stack->data->anim_fps--;
}

void move_enemy(t_so_long *stack, int counter)      ///// BIG CHANGE
{
	int old_pos_x;
	int old_pos_y;

    find_enemy(stack, counter + 1);
    old_pos_x = stack->enemy->pos_x[counter];
    old_pos_y = stack->enemy->pos_y[counter];
    if(stack->enemy->ctr != 0)
    {
        if (stack->enemy->fps == 1)
        {
            if(stack->level->level[old_pos_y][old_pos_x + 1] == '1' || stack->level->level[old_pos_y][old_pos_x + 1] == 'C' || stack->level->level[old_pos_y][old_pos_x + 1] == 'E')
                stack->enemy->flag[counter] = 0;
            if (stack->enemy->flag[counter] == 0)
            {
                if(stack->level->level[old_pos_y][old_pos_x - 1] == '0' || stack->level->level[old_pos_y][old_pos_x - 1] == 'P')
                {
                    if(stack->level->level[old_pos_y][old_pos_x - 1] == 'P')
                    {
                        printf("<--------YOU DED-------->\n");
                        mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
                        mlx_destroy_window(stack->data->mlx, stack->data->mlx_win);
                        exit(0);
                    }
                    stack->level->level[old_pos_y][old_pos_x] = '0';
                    stack->level->level[stack->enemy->pos_y[counter]][stack->enemy->pos_x[counter] - 1] = 'M';
                }
                if(stack->level->level[old_pos_y][old_pos_x - 1] == '1' || stack->level->level[old_pos_y][old_pos_x - 1] == 'C' || stack->level->level[old_pos_y][old_pos_x - 1] == 'E')
                    stack->enemy->flag[counter] = 1;
            }
            if(stack->enemy->flag[counter] == 1)
            {
                if(stack->level->level[old_pos_y][old_pos_x + 1] == '0' || stack->level->level[old_pos_y][old_pos_x + 1] == 'P')
                {
                    if(stack->level->level[old_pos_y][old_pos_x + 1] == 'P')
                    {
                        printf("<--------YOU DED-------->\n");
                        mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
                        mlx_destroy_window(stack->data->mlx, stack->data->mlx_win);
                        exit(0);
                    }
                    stack->level->level[old_pos_y][old_pos_x] = '0';
                    stack->level->level[stack->enemy->pos_y[counter]][stack->enemy->pos_x[counter] + 1] = 'M';
                }
            }
        }
    }
}
