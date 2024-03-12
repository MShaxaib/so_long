/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:52 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/12 07:10:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_level(char *level, t_so_long *stack)
{
	int	i;
	int	player_count;
	int	exit_count;

	i = 0;
	player_count = 0;
	exit_count = 0;
	stack->level->coins = 0;
	while (level[i] != '\0')
	{
		if (level[i] == 'P')
			player_count++;
		else if (level[i] == 'E')
			exit_count++;
		else if (level[i] == 'M')
			stack->enemy->ctr++;
		else if (level[i] == 'C')
			stack->level->coins++;
		else if (level[i] != '1' && level[i] != '0' && level[i] != '\n')
		{
			printf ("Non valid char found in map -- Exiting\n");
			exit (2);
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1 || stack->level->coins == 0)
	{
		printf ("Invalid level configuration -- Exiting\n");
		exit (2);
	}
}

void	checks(t_so_long *stack, char *level)
{
	stack->level->level = ft_split(level, '\n');
	check_level (level, stack);
	ractangle_check (level, stack);
	is_enclosed (level, stack);
	find_player (stack);
	find_exit (stack);
	if (path_finding (stack) == 0)
	{
		printf("no valid path to exit\n");
		exit(2);
	}
	stack->enemy->pos_x = calloc(sizeof(int), stack->enemy->ctr);
	stack->enemy->pos_y = calloc(sizeof(int), stack->enemy->ctr);
	stack->enemy->flag = calloc(sizeof(int), stack->enemy->ctr);
}

void	free_exit(t_so_long *stack, char *level)
{
	free(level);
	free(stack);
}

int	main(int ac, char **av)
{
	t_so_long	*stack;
	char		*level;

	if (ac != 2)
		return (1);
	level = read_level (av[1]);
	stack = malloc(sizeof(t_so_long));
	if (stack == NULL)
		return (1);
	init_level_stack(stack);
	checks (stack, level);
	level_init (stack);
	free_exit (stack, level);
	return (0);
}
