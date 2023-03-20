/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:39:26 by vasargsy          #+#    #+#             */
/*   Updated: 2023/03/19 18:55:58 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_addr(t_game *game)
{
	if (!(game->ea || game->so || game->we || game->no))
	{
		write(2, "Error: Image file could not found!\n", 35);
		list_free(game->mapp);
		free(game->mlx);
		exit(1);
	}
	game->img->addr[2] = mlx_get_data_addr(game->no,
			&game->img->bits_per_px[2], &game->img->size_len[2],
			&game->img->endian[2]);
	game->img->addr[3] = mlx_get_data_addr(game->so,
			&game->img->bits_per_px[3],
			&game->img->size_len[3], &game->img->endian[3]);
	game->img->addr[4] = mlx_get_data_addr(game->we,
			&game->img->bits_per_px[4],
			&game->img->size_len[4], &game->img->endian[4]);
	game->img->addr[5] = mlx_get_data_addr(game->ea,
			&game->img->bits_per_px[5],
			&game->img->size_len[5], &game->img->endian[5]);
}

void	getting_address(t_game *game, t_map *map)
{
	int		i;

	i = 64;
	game->no = mlx_xpm_file_to_image(game->mlx, map->texture->no, &i, &i);
	game->ea = mlx_xpm_file_to_image(game->mlx, map->texture->ea, &i, &i);
	game->so = mlx_xpm_file_to_image(game->mlx, map->texture->so, &i, &i);
	game->we = mlx_xpm_file_to_image(game->mlx, map->texture->we, &i, &i);
	get_addr(game);
}

void	player_init_angle(t_game *game, t_map *map)
{
	if (map->player == 'E')
		game->pa = 0;
	else if (map->player == 'N')
		game->pa = 90;
	else if (map->player == 'W')
		game->pa = 180;
	else if (map->player == 'S')
		game->pa = 270;
}
