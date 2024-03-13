/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:44:47 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/13 17:11:41 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_enclosed(char *level, t_so_long *stack)
{
	int	i;
	int	start_index;

	i = 0;
	start_index = (stack->level->rows - 1) * (stack->level->column + 1);
	while (level[i] != '\n')
		if (level[i++] != '1')
			exit(2);
	i = start_index;
	while (level[i] != '\0')
		if (level[i++] != '1')
			exit(2);
	i = 0;
	while (i < stack->level->rows)
	{
		if (level[i * (stack->level->column + 1)] != '1' \
		|| level[i * (stack->level->column + 1) + \
		stack->level->column - 1] != '1')
			exit(2);
		i++;
	}
}

char	find_startpoint(t_level *ls, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (ls->level[i] != NULL)
	{
		j = 0;
		while (ls->level[i][j] != '\0')
		{
			if (ls->level[i][j] == 'E' || ls->level[i][j] == 'P')
			{
				*x = i;
				*y = j;
				if (ls->level[i][j] == 'E')
					return ('P');
				else
					return ('E');
			}
			j ++;
		}
		i ++;
	}
	return ('\0');
}

int	init_visited(t_level *ls, int malloced)
{
	int	i;

	i = 0;
	while (i < ls->rows)
	{
		if (!malloced)
		{
			ls->visited[i] = malloc((ls->column) * sizeof(int));
			if (!ls->visited[i])
				return (0);
		}
		ft_memset(ls->visited[i], 0, ls->column * sizeof(int));
		i++;
	}
	return (1);
}

int	check_path(t_level *ls, int start_x, int start_y, char endpoint)
{
	if (ls->level[start_x][start_y] == endpoint)
		return (1);
	else if (ls->level[start_x][start_y] == '1')
		return (0);
	else if (start_x < 0 || start_y < 0 || start_x >= ls->rows \
	|| start_y >= ls->column || ls->visited[start_x][start_y])
		return (0);
	ls->visited[start_x][start_y] = 1;
	return (check_path(ls, start_x + 1, start_y, endpoint) \
	|| check_path(ls, start_x, start_y + 1, endpoint) \
	|| check_path(ls, start_x - 1, start_y, endpoint) \
	|| check_path(ls, start_x, start_y - 1, endpoint));
}

int	path_finding(t_so_long *stack)
{
	int		start_x;
	int		start_y;
	char	endpoint;

	start_x = 0;
	start_y = 0;
	stack->level->visited = malloc((stack->level->rows) * sizeof(int *));
	if (stack->level->visited == NULL)
		return (0);
	if (init_visited(stack->level, 0) == 0)
		return (0);
	endpoint = find_startpoint(stack->level, &start_x, &start_y);
	if (check_path(stack->level, start_x, start_y, endpoint) == 0)
		return (0);
	if (init_visited(stack->level, 1) == 0)
		return (0);
	return (1);
}
