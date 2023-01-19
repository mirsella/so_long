/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:00:43 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/19 16:19:59 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_textures(t_game *game)
{
	if (game->textures.wall != NULL)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor != NULL)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.player1 != NULL)
		mlx_destroy_image(game->mlx, game->textures.player1);
	if (game->textures.player2 != NULL)
		mlx_destroy_image(game->mlx, game->textures.player2);
	if (game->textures.player3 != NULL)
		mlx_destroy_image(game->mlx, game->textures.player3);
	if (game->textures.exit != NULL)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.exit_won != NULL)
		mlx_destroy_image(game->mlx, game->textures.exit_won);
	if (game->textures.collectible != NULL)
		mlx_destroy_image(game->mlx, game->textures.collectible);
	if (game->textures.patrol != NULL)
		mlx_destroy_image(game->mlx, game->textures.patrol);
}

int	free_exit(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_textures(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	exit(0);
}

void	exit_message(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(0);
}

void	exit_message_free_game(char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	free_exit(game);
}
