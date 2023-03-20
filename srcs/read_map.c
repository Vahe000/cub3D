/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:17:14 by leyeghia          #+#    #+#             */
/*   Updated: 2023/03/19 19:24:53 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_read_map(char *text)
{
	char	**line;
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(text, O_RDONLY);
	line = malloc(sizeof(char *) * (ft_map_len(fd) + 1));
	close(fd);
	fd = open(text, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (ft_only_whitespaces(str) == 0 || i > 6)
		{
			line[i] = ft_strtrim(str, "\n");
			++i;
		}
		ft_free_str(str);
	}
	line[i] = NULL;
	close(fd);
	return (line);
}
