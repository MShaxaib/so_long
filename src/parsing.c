/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:48 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/05 20:59:15 by mshazaib         ###   ########.fr       */
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

void check_level(char *level, t_so_long *stack)
{
    int i = 0;
    int player_count = 0;
    int exit_count = 0;
    int enemy_count = 0;
	
	stack->level->coins  = 0;
    while (level[i] != '\0')
    {
        if (level[i] == 'P')
            player_count++;
        else if (level[i] == 'E')
            exit_count++;
        else if (level[i] == 'M')
            enemy_count++;
        else if (level[i] == 'C')
            stack->level->coins++;
        else if (level[i] != '1' && level[i] != '0' && level[i] != '\n')
        {
            printf("Non valid char found in map -- Exiting\n");
            exit(2);
        }
        i++;
    }
    if (player_count != 1 || exit_count != 1 || stack->level->coins == 0)
    {
        printf("Invalid level configuration -- Exiting\n");
        exit(2);
    }
}
void ractangle_check(char *level, t_so_long *stack)
{
	int i;
	int j;
	int row_length;

	row_length = 0;
	i = 0;
	stack->level->rows = 1;
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
			stack->level->rows++;
			i++;
		}
	}
	stack->level->column = j;
}

void is_enclosed(char *level, t_so_long *stack) 
{
    int i; 
    int start_index;
	
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
        if (level[i * (stack->level->column + 1)] != '1' || 
            level[i * (stack->level->column + 1) + stack->level->column - 1] != '1') 
            exit(2);
        i++;
    }
}

void find_player(t_so_long *stack)
{
	int i;
	int j;
	int found;

	found = 0;
	i = 0;
	while(i < stack->level->rows && !found)
	{
		j = 0;
		while(j < stack->level->column && !found)
		{
			if(stack->level->level[i][j] == 'P')
			{
			stack->player->pos_y = i;
			stack->player->pos_x = j;
			found = 1;
			}
			j++;
		}
		i++;
	}
	if(!found)
		printf("Player not found\n");
}
void find_exit(t_so_long *stack)
{
	int i;
	int j;
	int found;

	found = 0;
	i = 0;
	while(i < stack->level->rows && !found)
	{
		j = 0;
		while(j < stack->level->column && !found)
		{
			if(stack->level->level[i][j] == 'E')
			{
			stack->player->pos_x = i;
			stack->player->pos_y = j;
			found = 1;
			}
			j++;
		}
		i++;
	}
	if(!found)
		printf("exit not found\n");
}
