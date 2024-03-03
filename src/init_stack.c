/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:27:15 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/03 22:44:18 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_level_stack(t_so_long *stack)
{
	// checks
	
	stack->level = malloc(sizeof(t_level));
	stack->data = malloc(sizeof(t_data));
	stack->player = malloc(sizeof(t_data));
	stack->exit = malloc(sizeof(t_data));
}