/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:46:23 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/20 17:42:10 by acmaghou         ###   ########.fr       */
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

typedef struct s_vars
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
	int		col;
	int		exits;
	int		player;
}	t_vars;

typedef struct s_res
{
	int	x;
	int	y;
}	t_res;

char	*get_next_line(int fd);
char	*str_ret(char *stc_arr);
char	*str_remainder(char *stc_arr, char *s);
int		find_nl(char *s);
char	**get_map(char *s);
int		keys(int keycode, t_vars *vars);
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*ft_strjoin1(char *s1, char *s2);
void	printmap(t_vars *vars, char **s);
void	left(t_vars *vars);
void	right(t_vars *vars);
void	up(t_vars *vars);
void	down(t_vars *vars);
void	countmoves(void);
void	printimages(t_vars *vars, char *s);
void	printassets(t_vars *vars, char c);
int		check_map(char **s, t_res *reso);
int		checklen(char **s);
void	free_all_rows(t_vars *vars);
char	*ft_strdup(char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		checkcomp(t_vars *vars, char **s);
void	countassets(t_vars *vars, char c);

#endif