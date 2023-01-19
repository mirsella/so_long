/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:17:14 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/15 15:11:41 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_patrol(t_game *game, size_t *i, size_t *j)
{
	if (game->map[*i][*j + game->patrol_direction] == '0'
			|| game->map[*i][*j + game->patrol_direction] == 'P' )
	{
		game->map[*i][*j] = '0';
		game->map[*i][*j + game->patrol_direction] = 'X';
		if (game->patrol_direction == 1)
			(*j)++;
		return (1);
	}
	return (0);
}

void	move_patrols(t_game *game)
{
	static size_t	counter = 0;
	size_t			i;
	size_t			j;
	int				moved;

	if (counter < PATROL_DELAY)
	{
		counter++;
		return ;
	}
	counter = 0;
	moved = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'X')
				if (move_patrol(game, &i, &j))
					moved++;
		}
	}
	if (moved == 0)
		game->patrol_direction *= -1;
}
