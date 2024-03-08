/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:52 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/08 17:04:00 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void checks(t_so_long *stack, char *level)
{
	stack->level->level = ft_split(level, '\n'); // memory stack
	check_level(level, stack);
	ractangle_check(level,stack);
	is_enclosed(level, stack);
	find_player(stack);
	find_exit(stack);
	if (path_finding(stack) == 0) // memory stack
		{
			printf("no valid path to exit\n");
			exit(2);
		}
}

// void update(t_so_long *stack)
// {
	
// }

void free_exit(t_so_long *stack, char *level)
{
	free(level);
	free(stack);
}

int main(int ac, char **av)
{
	t_so_long *stack;
	char *level;
	
	if(ac != 2)
		return 1;
	level = read_level(av[1]);
	stack = malloc(sizeof(t_so_long));
	if(stack == NULL)
		return 1;
	init_level_stack(stack);
	checks(stack, level);
	level_init(stack);
	free_exit(stack, level);
	return(0);
}
