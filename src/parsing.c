/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:48 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/13 18:22:55 by vtcsbza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printandexit(const char *error, int error_code)
{
	int	len;

	len = 0;
	while (error[len] != '\0')
		len++;
	write (1, error, len);
	write (1, "\n", 1);
	exit (error_code);
}

char	*read_level(char *levelname)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];
	char	*level_bytes;

	level_bytes = NULL;
	fd = open(levelname, O_RDONLY);
	if (fd == -1)
		printandexit("Error Opening File", 2);
	level_bytes = malloc(BUFFER_SIZE * sizeof(char));
	if (level_bytes == NULL)
		printandexit("Error allocating memory", 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		printandexit("Error reading file", 1);
	close(fd);
	ft_memcpy(level_bytes, buffer, bytes_read);
	level_bytes[bytes_read] = '\0';
	return (level_bytes);
}

void	ractangle_check(char *level, t_so_long *stack)
{
	int	i;
	int	j;
	int	row_length;

	row_length = 0;
	i = 0;
	stack->level->rows = 1;
	while (level[i] != '\0')
	{
		j = 0;
		while (level[i] != '\0' && level[i] != '\n')
		{
			i++;
			j++;
		}
		if (row_length == 0)
			row_length = j;
		else if (row_length != j)
				printandexit("Map is not rectangle", 1);
		if (level[i] == '\n')
		{
			stack->level->rows++;
			i++;
		}
	}
	stack->level->column = j;
}

void	find_player(t_so_long *stack)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (i < stack->level->rows && !found)
	{
		j = 0;
		while (j < stack->level->column && !found)
		{
			if (stack->level->level[i][j] == 'P')
			{
				stack->player->pos_y = i;
				stack->player->pos_x = j;
				found = 1;
			}
			j++;
		}
		i++;
	}
	if (!found)
		write(1, "Player not found\n", 18);
}

void	find_exit(t_so_long *stack)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (i < stack->level->rows && !found)
	{
		j = 0;
		while (j < stack->level->column && !found)
		{
			if (stack->level->level[i][j] == 'E')
			{
				stack->player->pos_x = i;
				stack->player->pos_y = j;
				found = 1;
			}
			j++;
		}
		i++;
	}
	if (!found)
		write(1, "exit not found\n", 16);
}
