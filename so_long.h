/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:46:23 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/18 14:34:21 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1024

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**s;
	int		x;
	int		y;
	int		h;
	int		b;
	int		d;
	int		px;
	int		py;
	int		w;
	int		len;
} t_vars;

typedef struct s_res
{
	int	x;
	int	y;
} t_res;

char	*get_next_line(int fd);
char	*ft_change_text(char *text);
char	*ft_just_a_line(char *text);
char	*ft_read(char *text, int fd);
char	**get_map(char *s);
int		my_kf(int keycode, t_vars *he);
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*ft_strjoin1(char *s1, char *s2);
void	printmap(t_vars *he, char **s);
void	left(t_vars *he);
void	right(t_vars *he);
void	up(t_vars *he);
void	down(t_vars *he);
void	countmoves(t_vars *he);
int		ft_checkc(t_vars *he);
void	ft_print_m(t_vars *he);
char	*ft_itoa(int n);
void	printimg(t_vars *he, char *s);
void	printe(t_vars *he, char c);
int		check_map(char **s, t_res *xe);
int		checklen(char **s);
void	free_all(t_vars *he);
char	*ft_strdup(char *str);

#endif