/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:26:34 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/19 16:21:34 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_argv(int argc, char **argv)
{
	if (argc != 2)
		exit_message("wrong size of arguments");
	if (ft_strlen(argv[1]) < 5)
		exit_message("wrong file name, not a .ber");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		exit_message("wrong file name, not a .ber");
	return (1);
}

int	frame(t_game *game)
{
	move_patrols(game);
	draw_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_argv(argc, argv);
	ft_bzero(&game, sizeof(t_game));
	game.patrol_direction = -1;
	load_map(&game, argv[1]);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit_message("mlx_init failed");
	load_textures(&game);
	game.win = mlx_new_window(game.mlx, game.map_width * RESOLUTION,
			game.map_height * RESOLUTION, "so_long");
	if (!game.win)
		exit_message("mlx_new_window failed");
	mlx_hook(game.win, 17, 0, free_exit, &game);
	mlx_key_hook(game.win, handle_keycode, &game);
	mlx_loop_hook(game.mlx, frame, &game);
	mlx_loop(game.mlx);
}
