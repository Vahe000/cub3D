/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:32:57 by vasargsy          #+#    #+#             */
/*   Updated: 2023/03/18 19:00:50 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst -> next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (!node)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
}

void	put_map_sym(int mx, int my, t_game *game, char c)
{
	char	*str;
	t_list	*map;

	if (mx < 0 || my < 0)
		return ;
	map = game->mapp;
	while (my > 0)
	{
		my--;
		map = map->next;
	}
	str = map->content;
	str[mx] = c;
}

double	calc_dist(t_ray *ray)
{
	double	x;

	x = cos(degree_to_radian(ray->ra)) * (ray->rx - ray->px)
		- sin(degree_to_radian(ray->ra)) * (ray->ry - ray->py);
	return (x);
}
