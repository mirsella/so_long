/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:56:18 by lgillard          #+#    #+#             */
/*   Updated: 2023/01/20 15:28:31 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_there_path(char **map, t_pos a, t_pos b)
{
	if (a.x == b.x && a.y == b.y)
		return (1);
	if (map[a.y][a.x] == '0' || map[a.y][a.x] == 'C'
		|| map[a.y][a.x] == 'X' || map[a.y][a.x] == 'P')
	{
		map[a.y][a.x] = 'V';
		if (is_there_path(map, (t_pos){a.x, a.y - 1}, b))
			return (1);
		if (is_there_path(map, (t_pos){a.x - 1, a.y}, b))
			return (1);
		if (is_there_path(map, (t_pos){a.x, a.y + 1}, b))
			return (1);
		if (is_there_path(map, (t_pos){a.x + 1, a.y}, b))
			return (1);
	}
	return (0);
}

void	check_map_path(t_game *game, size_t i, size_t j)
{
	t_pos	player;
	char	**map;

	player = get_player_pos(game);
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'E' || game->map[i][j] == 'C')
			{
				map = ft_strstrdup(game->map);
				if (!is_there_path(map, player, (t_pos){j, i}))
				{
					free_map(map);
					exit_message_free_game("no valid path for a item", game);
				}
				free_map(map);
			}
		}
	}
}
