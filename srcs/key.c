/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:21:55 by vasargsy          #+#    #+#             */
/*   Updated: 2023/03/19 15:08:58 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_a(t_game *game)
{
	int		my;
	int		mx;
	char	val;

	mx = game->player->posx + (game->player->diry * 0.2);
	my = game->player->posy - (game->player->dirx * 0.2);
	val = get_map_sym(mx, my, game);
	if (val == '0' || val == 'K')
	{
		if (val == 'K')
			put_map_sym(mx, my, game, '0');
		game->player->posx += (game->player->diry * 0.1);
		game->player->posy -= (game->player->dirx * 0.1);
		if (game->step_num)
			game->step_num += 1;
	}
}

void	key_w(t_game *game)
{
	int		my;
	int		mx;
	char	val;

	mx = game->player->posx + (game->player->dirx * 0.2);
	my = game->player->posy + (game->player->diry * 0.2);
	val = get_map_sym(mx, my, game);
	if (val == '0' || val == 'K')
	{
		if (val == 'K')
			put_map_sym(mx, my, game, '0');
		game->player->posx += (game->player->dirx * 0.1);
		game->player->posy += (game->player->diry * 0.1);
		if (game->step_num)
			game->step_num += 1;
	}
}

void	key_d(t_game *game)
{
	int		my;
	int		mx;
	char	val;

	mx = game->player->posx - (game->player->diry * 0.2);
	my = game->player->posy + (game->player->dirx * 0.2);
	val = get_map_sym(mx, my, game);
	if (val == '0' || val == 'K')
	{
		if (val == 'K')
			put_map_sym(mx, my, game, '0');
		game->player->posx -= (game->player->diry * 0.1);
		game->player->posy += (game->player->dirx * 0.1);
		if (game->step_num)
			game->step_num += 1;
	}
}

void	key_s(t_game *game)
{
	int		my;
	int		mx;
	char	val;

	mx = game->player->posx - (game->player->dirx * 0.2);
	my = game->player->posy - (game->player->diry * 0.2);
	val = get_map_sym(mx, my, game);
	if (val == '0' || val == 'K')
	{
		if (val == 'K')
			put_map_sym(mx, my, game, '0');
		game->player->posx -= (game->player->dirx * 0.1);
		game->player->posy -= (game->player->diry * 0.1);
		if (game->step_num)
			game->step_num += 1;
	}
}

int	key_hooks(int key, t_game *game)
{
	if (key == 13)
		key_w(game);
	else if (key == 0)
		key_a(game);
	else if (key == 1)
		key_s(game);
	else if (key == 2)
		key_d(game);
	else if (key == 53)
		game_end(game);
	else if (key == 123)
		l_key(game);
	else if (key == 124)
		r_key(game);
	return (0);
}
