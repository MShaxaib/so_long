/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitandfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:43:43 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/03/04 19:45:25 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    exitandfree(t_so_long *stack)
{
    mlx_clear_window(stack->data->mlx, stack->data->mlx_win);
    mlx_destroy_window(stack->data->mlx, stack->data->mlx_win);
    exit(0);
}