/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:40:19 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/03/08 17:52:40 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void move_enemy(t_so_long *stack)
// {
//     for (int i = 0; stack->level->level[i] != NULL; i++)
//     {
//         for (int j = 0; stack->level->level[i][j] != '\0'; j++)
//         {
//             if (stack->level->level[i][j] == 'M')
//             {
//                 if (i > 0 && stack->level->level[i - 1][j] != '1')
//                 {
//                     stack->level->level[i - 1][j] = 'M';
//                     stack->level->level[i][j] = '0';
//                     mlx_put_image_to_window(stack->data->mlx, stack->data->mlx_win, stack->data->img_enemy,\
// 					 (stack->level->level[0][j]) * 64, (stack->level->level[i][0] - 1) * 64);
//                 }
//             }
//         }
//     }
// }

void move_enemy(t_so_long *stack)
{
    
    // Find the enemy
    find_enemy(stack);

    int old_pos_x = stack->enemy->pos_x;
    int old_pos_y = stack->enemy->pos_y;

if(stack->enemy->fps == 1)
{
    // printf("flag %d\n", flag);
    if (stack->enemy->flag == 0)
    {
        if(stack->level->level[old_pos_y][old_pos_x - 1] != '1')
        {
            stack->level->level[old_pos_y][old_pos_x] = '0';
            stack->level->level[stack->enemy->pos_y][stack->enemy->pos_x - 1] = 'M';
        }    
        else if(stack->level->level[old_pos_y][old_pos_x - 1] == '1')
            stack->enemy->flag = 1;
    }
    else if(stack->enemy->flag == 1)
    {
        if(stack->level->level[old_pos_y][old_pos_x + 1] != '1')
        {
            stack->level->level[old_pos_y][old_pos_x] = '0';
            stack->level->level[stack->enemy->pos_y][stack->enemy->pos_x + 1] = 'M';
        }
        else if(stack->level->level[old_pos_y][old_pos_x + 1] == '1')
            stack->enemy->flag = 0;
    }
}
    stack->enemy->fps--;
}