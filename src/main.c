/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:52 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/27 20:12:54 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*

	The map has to be constructed with 3 components: walls, collectibles, and free
	space.
	
	• The map can be composed of only these 5 characters:
	!		0 for an empty space,
	!		1 for a wall,
	!		C for a collectible,
	!		E for a map exit,
	!		P for the player’s starting position.
	
	Here is a simple valid map:
	
	1111111111111
	10010000000C1
	1000011111001
	1P0011E000001
	1111111111111
	
	• The map must contain 1 exit, at least 1 collectible, and 1 starting position to
	be valid.

*/

int main(int ac, char **av)
{
	char *level;
	int i = 0;
	t_level *level_stack;

	if(ac != 2)
		return 1;

	level_stack = malloc(sizeof(t_level));
	if(level_stack == NULL)
		return 1;
	level = read_level(av[1]);
	level_stack->level = ft_split(level, '\n');
	check_level(level, level_stack);
	ractangle_check(level,level_stack);
	is_enclosed(level, level_stack);
	find_player(level_stack);
	find_exit(level_stack);
	printf("\n\n");
	i = 0;
	while(level[i] != '\0')
	{
		printf("%c", level[i]);
		i++;
	}
	printf("\n\n");
	free(level);
	free(level_stack);
	return(0);
}
