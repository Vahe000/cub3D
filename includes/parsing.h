/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:07:21 by leyeghia          #+#    #+#             */
/*   Updated: 2023/03/14 12:57:14 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "get_next_line.h"

# define ALLCHARS " 01NSWE"
# define EXCHARS "01NSWE"

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}				t_colors;

typedef struct s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_colors	*floor;
	t_colors	*ceiling;
}				t_texture;

typedef struct s_map
{
	t_texture	*texture;
	char		**map;
	char		player;
	double		px;
	double		py;
	int			map_width;
	int			map_height;
}				t_map;

void	parsing(t_map *map, char *text);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char *s1, char *set);
long	ft_atoi(const char *str);
char	**ft_split_space(char *str);

size_t	ft_matrix_size(char **matrix);
int		ft_map_len(int fd);
char	**ft_read_map(char *text);

int		ft_only_whitespaces(char *str);
int		ft_is_whitespace(char c);
int		ft_isdigit(char **a);
size_t	matrix_strlen(const char *str);

void	pars_rgb(t_texture *map, char **line);
int		pars_nswe(t_texture *texture, char **line);
void	pars_map(t_map *map, char **line);

void	check_nswe(char **line);
void	check_commas(char **line);
int		check_patf_format(t_texture *texture);
int		check_map(char **line);
int		check_map2(t_map *map);

void	change_line(char **line);

//free
void	free_arr(char **arr);
void	ft_free_str(char *cmd);
void	free_all(t_map *map);

#endif