/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:13:02 by vasargsy          #+#    #+#             */
/*   Updated: 2023/03/19 16:59:10 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		game->map = malloc(sizeof(t_map));
		if (!game || !game->map)
			return (1);
		parsing(game->map, argv[1]);
		init_struct(game);
		game_start(game, game->map);
	}
	else
		ft_putstr_fd("Error: invalid number of arguments\n", 2);
	return (1);
}
