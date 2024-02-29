/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:03:22 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/29 18:17:21 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	level_init(t_level *level)
{
	void	*mlx;
	void 	*mlx_win;
	
	mlx = mlx_init();
	printf("number of columns %d\n", level->column);
	printf("number of rows %d\n", level->rows);
	mlx_win = mlx_new_window(mlx, level->rows * 64, level->column * 128, "test_mlx");
	mlx_loop(mlx);
}