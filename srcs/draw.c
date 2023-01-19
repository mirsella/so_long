/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:02:46 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/15 15:13:53 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_game *game, size_t x, size_t y)
{
	if (game->won == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit,
			x * RESOLUTION, y * RESOLUTION);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit_won,
			x * RESOLUTION, y * RESOLUTION);
	}
}

void	draw_player(t_game *game, size_t x, size_t y)
{
	static size_t	counter = 0;

	if (counter < ANIMATION_DELAY)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->textures.player1,
			x * RESOLUTION, y * RESOLUTION);
	}
	else if (counter < ANIMATION_DELAY * 2)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->textures.player2,
			x * RESOLUTION, y * RESOLUTION);
	}
	else if (counter < ANIMATION_DELAY * 3)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->textures.player3,
			x * RESOLUTION, y * RESOLUTION);
	}
	if (counter >= ANIMATION_DELAY * 3)
		counter = 0;
	else
		counter++;
}

void	call_drawer(t_game *game, size_t x, size_t y)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.floor, x * RESOLUTION, y * RESOLUTION);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.wall, x * RESOLUTION, y * RESOLUTION);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, x * RESOLUTION, y * RESOLUTION);
	else if (game->map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.patrol,
			x * RESOLUTION, y * RESOLUTION);
	else if (game->map[y][x] == 'E')
		draw_exit(game, x, y);
	else if (game->map[y][x] == 'P')
		draw_player(game, x, y);
}

void	draw_game(t_game *game)
{
	size_t	y;
	size_t	x;
	char	*tmp;
	char	*str;

	tmp = ft_itoa(game->movement_count);
	str = ft_strjoin("Movement count: ", tmp);
	free(tmp);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			call_drawer(game, x, y);
			if (y == 0 && x <= 120 / RESOLUTION)
				mlx_string_put(game->mlx, game->win, 10, 15, 0xFFFFFF, str);
			x++;
		}
		y++;
	}
	free(str);
}
