/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:35:29 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/19 16:21:34 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_textures(t_game *game)
{
	if (!game->textures.wall)
		exit_message_free_game("wall texture is missing", game);
	if (!game->textures.floor)
		exit_message_free_game("floor texture is missing", game);
	if (!game->textures.player1)
		exit_message_free_game("player1 texture is missing", game);
	if (!game->textures.player2)
		exit_message_free_game("player2 texture is missing", game);
	if (!game->textures.player3)
		exit_message_free_game("player3 texture is missing", game);
	if (!game->textures.exit)
		exit_message_free_game("exit texture is missing", game);
	if (!game->textures.exit_won)
		exit_message_free_game("exit_won texture is missing", game);
	if (!game->textures.collectible)
		exit_message_free_game("collectible texture is missing", game);
	if (!game->textures.patrol)
		exit_message_free_game("patrol texture is missing", game);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &width, &height);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor.xpm", &width, &height);
	game->textures.player1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/player1.xpm", &width, &height);
	game->textures.player2 = mlx_xpm_file_to_image(game->mlx,
			"./textures/player2.xpm", &width, &height);
	game->textures.player3 = mlx_xpm_file_to_image(game->mlx,
			"./textures/player3.xpm", &width, &height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &width, &height);
	game->textures.exit_won = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit_won.xpm", &width, &height);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm", &width, &height);
	game->textures.patrol = mlx_xpm_file_to_image(game->mlx,
			"./textures/patrol.xpm", &width, &height);
	check_textures(game);
}
