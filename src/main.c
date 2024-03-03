/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:52 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/03 22:03:39 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void checks(t_level *level_stack, char *level)
{

	level_stack->level = ft_split(level, '\n'); // memory stack
	check_level(level, level_stack);
	ractangle_check(level,level_stack);
	is_enclosed(level, level_stack);
	find_player(level_stack);
	find_exit(level_stack);
	if (path_finding(level_stack) == 0) // memory stack
		{
			printf("no valid path to exit\n");
			exit(2);
		}
}

void free_exit(t_level *level_stack, char *level)
{
	free(level);
	free(level_stack);
}

int main(int ac, char **av)
{
	t_level *level_stack;
	char *level;
	
	if(ac != 2)
		return 1;
	level = read_level(av[1]);
	level_stack = malloc(sizeof(t_level));
	if(level_stack == NULL)
		return 1;
	checks(level_stack, level);
	level_init(level_stack);
	free_exit(level_stack, level);
	return(0);
}
