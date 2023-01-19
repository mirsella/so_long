/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:00:14 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/15 14:18:59 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	get_player_pos(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
				return ((t_pos){x, y});
			x++;
		}
		y++;
	}
	return ((t_pos){0, 0});
}

int	how_many_in_map(char **map, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	move_player(t_game *game, int x, int y)
{
	t_pos	p;
	char	next_pos;

	p = get_player_pos(game);
	if (p.x == 0 && p.y == 0)
		return ;
	next_pos = game->map[p.y + y][p.x + x];
	if (next_pos == '1'
		|| (next_pos == 'E' && how_many_in_map(game->map, 'C') > 0))
		return ;
	game->map[p.y][p.x] = '0';
	if (next_pos == '0' || next_pos == 'C')
		game->map[p.y + y][p.x + x] = 'P';
	else if (next_pos == 'E')
		game->won = 1;
	game->movement_count++;
}

int	handle_keycode(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		free_exit(game);
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(game, 0, -1);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(game, 0, 1);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(game, -1, 0);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(game, 1, 0);
	return (0);
}
