/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:48 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/25 14:12:58 by codespace        ###   ########.fr       */
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
	if (fd == -1) {
		perror("Error opening file");
		exit(2);
	}
	
	level_bytes = malloc(BUFFER_SIZE * sizeof(char));
	if (level_bytes == NULL) {
		perror("Error allocating memory");
		exit(1);
	}

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1) {
		perror("Error reading file");
		exit(1);
	}

	close(fd);
	memcpy(level_bytes, buffer, bytes_read);
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
