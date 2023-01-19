/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:04:59 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/19 16:20:30 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_lines(char *filename)
{
	int		fd;
	char	*line;
	size_t	lines;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_message(strerror(errno));
	line = ft_get_next_line(fd, 0);
	while (line)
	{
		free(line);
		lines++;
		line = ft_get_next_line(fd, 0);
	}
	free(line);
	close(fd);
	return (lines);
}

void	check_map_items(t_game *game, size_t i, size_t j)
{
	int		exit;
	int		collectible;
	int		player;

	exit = 0;
	collectible = 0;
	player = 0;
	while (i--)
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				player++;
			else if (game->map[i][j] == 'C')
				collectible++;
			else if (game->map[i][j] == 'E')
				exit++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0'
					&& game->map[i][j] != 'X')
				exit_message_free_game("wrong character in map", game);
		}
	}
	if (exit != 1 || collectible == 0 || player != 1)
		exit_message_free_game("wrong number of items in map", game);
}

void	check_map(t_game *game)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (game->map[0] == NULL)
		exit_message_free_game("empty file", game);
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (len != ft_strlen(game->map[i]))
			exit_message_free_game("map is not rectangular", game);
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			exit_message_free_game("map is not closed by 1", game);
		i++;
	}
	game->map_height = i;
	game->map_width = len;
	while (len--)
		if (game->map[0][len] != '1' || game->map[i - 1][len] != '1')
			exit_message_free_game("map is not closed by 1", game);
	check_map_items(game, i, len);
}

void	load_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_message(strerror(errno));
	game->map = malloc(sizeof(char *) * (count_lines(filename) + 1));
	if (!game->map)
	{
		close(fd);
		exit_message("malloc failed");
	}
	line = ft_get_next_line(fd, 0);
	while (line)
	{
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = ft_get_next_line(fd, 0);
	}
	game->map[i] = NULL;
	close(fd);
	check_map(game);
}
