/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:26:36 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/20 15:13:49 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include "stdlib.h"
# include <errno.h>
# include <string.h>
# include <X11/keysym.h>

# define RESOLUTION 40

# ifndef ANIMATION_DELAY
#  define ANIMATION_DELAY 400
# endif

# ifndef PATROL_DELAY
#  define PATROL_DELAY 200
# endif

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*exit;
	void	*exit_won;
	void	*collectible;
	void	*patrol;
}				t_textures;

typedef struct game
{
	void				*mlx;
	void				*win;
	char				**map;
	size_t				map_width;
	size_t				map_height;
	t_textures			textures;
	unsigned long long	movement_count;
	int					patrol_direction;
	int					won;
}				t_game;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

void	load_map(t_game *game, char *filename);
void	check_map_path(t_game *game, size_t i, size_t j);
void	load_textures(t_game *game);
void	move_patrols(t_game *game);
t_pos	get_player_pos(t_game *game);
int		handle_keycode(int keycode, t_game *game);
void	draw_game(t_game *game);
int		free_exit(t_game *game);
void	free_map(char **map);
void	exit_message(char *message);
void	exit_message_free_game(char *message, t_game *game);

#endif
