/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:46 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/27 08:31:50 by codespace        ###   ########.fr       */
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

void init_level_stack();
int  read_level(char *levelname, t_level *level_stack);
void check_level(t_level *level_stack);
void ractangle_check(char *level, t_level *level_stack);
void is_enclosed(char *level, t_level *level_stack);
void find_player_exit(char *level, t_level *level_stack);

// Utils
char	**ft_split(char const *src, char delim);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char const *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);