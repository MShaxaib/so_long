/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:48 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/27 20:14:25 by mshazaib         ###   ########.fr       */
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

void find_player(t_level *level_stack)
{
	int i;
	int j;
	int found;
	t_player *player_stack;

	player_stack = malloc(sizeof(t_level));
	found = 0;
	i = 0;
	while(i < level_stack->rows && !found)
	{
		j = 0;
		while(j < level_stack->column && !found)
		{
			if(level_stack->level[i][j] == 'P')
			{
			player_stack->pos_x = i;
			player_stack->pos_y = j;
			found = 1;
			}
			j++;
		}
		i++;
	}
	if(!found)
		printf("Player not found\n");
	printf("player is at X[%d] Y[%d]\n", player_stack->pos_x,player_stack->pos_y);
}
void find_exit(t_level *level_stack)
{
	int i;
	int j;
	int found;
	t_exit *exit_stack;

	exit_stack = malloc(sizeof(t_level));
	found = 0;
	i = 0;
	while(i < level_stack->rows && !found)
	{
		j = 0;
		while(j < level_stack->column && !found)
		{
			if(level_stack->level[i][j] == 'E')
			{
			exit_stack->pos_x = i;
			exit_stack->pos_y = j;
			found = 1;
			}
			j++;
		}
		i++;
	}
	if(!found)
		printf("exit not found\n");
	printf("Exit is at   X[%d] Y[%d]\n", exit_stack->pos_x,exit_stack->pos_y);
}
