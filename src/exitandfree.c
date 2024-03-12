/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitandfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:43:43 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/03/12 17:13:47 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exitandfree(t_so_long *stack, int flag)
{
	if (flag == 1)
		printf("<-----------YOU WIN------------>\n");
	else
		printf("<-----------YOU DED------------>\n");
	mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
	mlx_destroy_image(stack->data->mlx, stack->data->img_coin);
	mlx_destroy_image(stack->data->mlx, stack->data->img_enemy);
	mlx_destroy_image(stack->data->mlx, stack->data->img_wall);
	mlx_destroy_image(stack->data->mlx, stack->data->img_exit);
	mlx_destroy_image(stack->data->mlx, stack->data->background);
	mlx_destroy_image(stack->data->mlx, stack->data->background_d);
	mlx_destroy_window(stack->data->mlx, stack->data->mlx_win);
	exit(0);
}
