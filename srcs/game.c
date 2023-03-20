/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:07:40 by vasargsy          #+#    #+#             */
/*   Updated: 2023/03/19 18:14:13 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	list_free(game->mapp);
	if (game->img->img)
		mlx_destroy_image(game->mlx, game->img->img);
	free(game->mlx);
	free(game->line);
}

int	game_end(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_window);
	free_game(game);
	exit(0);
}

void	r_key(t_game *game)
{
	game->pa -= 5;
	game->pa = replace_angle_360(game->pa);
	game->player->dirx = cos(degree_to_radian(game->pa));
	game->player->diry = -1 * sin(degree_to_radian(game->pa));
}

void	l_key(t_game *game)
{
	game->pa += 5;
	game->pa = replace_angle_360(game->pa);
	game->player->dirx = cos(degree_to_radian(game->pa));
	game->player->diry = -1 * sin(degree_to_radian(game->pa));
}

void	game_start(t_game *game, t_map *map)
{
	player_init_angle(game, map);
	game->player->dirx = cos(degree_to_radian(game->pa));
	game->player->diry = -1 * sin(degree_to_radian(game->pa));
	game->mlx = mlx_init();
	getting_address(game, map);
	game->mlx_window = mlx_new_window(game->mlx, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	mlx_hook(game->mlx_window, 17, 0, game_end, game);
	mlx_hook(game->mlx_window, 2, 0, key_hooks, game);
	mlx_loop_hook(game->mlx, start_game, game);
	mlx_loop(game->mlx);
}
