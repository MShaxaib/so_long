/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:46 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/27 20:09:40 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//to be replaced my my own libft
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct t_level
{
	int rows;
	int column;
	int coins;
	int player_pos;
	int exit_pos;
	char **level;
}			t_level;

typedef struct t_player
{
	int pos_x;
	int pos_y;
}		t_player;

typedef struct t_exit
{
	int pos_x;
	int pos_y;
}		t_exit;

void init_level_stack();
char *read_level();
void check_level(char *level, t_level *level_stack);
void ractangle_check(char *level, t_level *level_stack);
void is_enclosed(char *level, t_level *level_stack);
void find_player(t_level *level_stack);
void find_exit(t_level *level_stack);

//

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);