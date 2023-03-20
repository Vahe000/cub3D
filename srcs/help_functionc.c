/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functionc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:13:32 by leyeghia          #+#    #+#             */
/*   Updated: 2023/02/27 12:48:21 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	matrix_strlen(const char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str && str[i])
	{
		if (str[i] == '\t')
			len += 3;
		++i;
	}	
	return (i + len);
}

int	ft_isdigit(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a && a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if ((a[i][j] >= '0' && a[i][j] <= '9') || a[i][j] == 32
				|| a[i][j] == '\t')
				++j;
			else
				return (2);
		}
		++i;
	}
	return (0);
}

int	ft_is_whitespace(char c)
{
	int	i;

	i = 0;
	if (c == 32 || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\b'
		|| c == '\f' || c == '\a')
		return (1);
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
