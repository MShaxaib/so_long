/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:58:46 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/03 22:56:07 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../MLX/mlx.h"

//to be replaced my my own libft
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct t_level
{
	int rows;
	int column;
	int coins;
	int	**visited;
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

typedef struct t_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_coin;
	void	*img_enemy;
	void	*background;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*path;
	int		w;
	int		h;
}		t_data;

typedef struct t_so_long
{
	t_data *data;
	t_level *level;
	t_exit *exit;
	t_player *player;
}		t_so_long;

void init_level_stack(t_so_long *stack);
char *read_level(char *levelname);
void check_level(char *level, t_so_long *stack);
void ractangle_check(char *level, t_so_long *stack);
void is_enclosed(char *level, t_so_long *stack);
void find_player(t_so_long *stack);
void find_exit(t_so_long *stack);

//

int check_path(t_level *ls, int start_x, int start_y, char endpoint);
int path_finding(t_so_long *stack);
int init_visited(t_level *ls, int malloced);

//

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);

// MLX

void	level_init(t_so_long *stack);

// Player_controller

void player_controller(t_so_long *stack, char dir);