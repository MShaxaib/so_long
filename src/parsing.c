/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:48 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/26 17:28:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_level(char *levelname) 
{
	int fd;
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];
	char *level_bytes = NULL;

	fd = open(levelname, O_RDONLY);
	if (fd == -1) 
	{
		perror("Error opening file");
		exit(2);
	}
	
	level_bytes = malloc(BUFFER_SIZE * sizeof(char));
	if (level_bytes == NULL) 
	{
		perror("Error allocating memory");
		exit(1);
	}

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1) 
	{
		perror("Error reading file");
		exit(1);
	}
	close(fd);
	memcpy(level_bytes, buffer, bytes_read); 		//& nned to be replaced by ft_memcpy
	level_bytes[bytes_read] = '\0';
	return (level_bytes);
}

void check_level(char *level, t_level *level_stack)
{
    int i = 0;
    int player_count = 0;
    int exit_count = 0;
	
	level_stack->coins  = 0;

    while (level[i] != '\0')
    {
        if (level[i] == 'P')
            player_count++;
        else if (level[i] == 'E')
            exit_count++;
        else if (level[i] == 'C')
            level_stack->coins++;
        else if (level[i] != '1' && level[i] != '0' && level[i] != '\n')
        {
            printf("Non valid char found in map -- Exiting\n");
            exit(2);
        }
        i++;
    }
    if (player_count != 1 || exit_count != 1 || level_stack->coins == 0)
    {
        printf("Invalid level configuration -- Exiting\n");
        exit(2);
    }
	printf("Number of coins : %d\n", level_stack->coins);
}
void ractangle_check(char *level, t_level *level_stack)
{
	int i;
	int j;
	int row_length;

	row_length = 0;
	i = 0;
	level_stack->rows = 1;
	while(level[i] != '\0')
	{
		j = 0;
		while(level[i] != '\0' && level[i] != '\n')
		{
			i++;
			j++;
		}
		if(row_length == 0)
			row_length = j;
		else
		{
			
			if(row_length != j)
			{
				printf("Map is not rectangle\n");
				exit(2);
			}
		}
		if(level[i] == '\n')
		{
			level_stack->rows++;
			i++;
		}
	}
	level_stack->column = j;
	printf("Number of rows in the map are %d\n", level_stack->rows);
	printf("Number of columns in the map are %d\n", j);
}

void is_enclosed(char *level, t_level *level_stack) 
{
    int i; 
    int start_index;
	
	i = 0;
	start_index = (level_stack->rows - 1) * (level_stack->column + 1);
    while (level[i] != '\n') 
        if (level[i++] != '1') 
            exit(2);
    i = start_index;
    while (level[i] != '\0')
        if (level[i++] != '1') 
            exit(2);
    i = 0;
    while (i < level_stack->rows) 
	{
        if (level[i * (level_stack->column + 1)] != '1' || 
            level[i * (level_stack->column + 1) + level_stack->column - 1] != '1') 
            exit(2);
        i++;
    }
}

void find_player_exit(char *level, t_level *level_stack)
{
	int player_pos;
	int exit_pos;

	player_pos = 0;
	exit_pos = 0;

	while(level[player_pos] != 'P')
		player_pos++;
	while(level[exit_pos] != 'E')
		exit_pos++;
	level_stack->player_pos = player_pos;
	level_stack->exit_pos = exit_pos;
	printf("player pos is %d\n", player_pos);
	printf("exit pos is %d\n", exit_pos);
}

void path_finding(char *level, t_level *level_stack)
{
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	int path_finder = 0;

	while(path_finder != level_stack->exit_pos)
	{
		path_finder = level_stack->player_pos;
		if(level[path_finder + 1] == '1')
	}
}