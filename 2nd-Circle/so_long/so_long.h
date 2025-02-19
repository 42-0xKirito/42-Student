/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:49:41 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/19 06:15:00 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <libft.h>

typedef struct	s_col
{
	int				x;
	int				y;
	int				val;
	struct s_col	*next;
}				t_col;


typedef	struct	s_val
{
	int	i;
	int	k;
	int	j;
}				t_val;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef	struct	s_map
{
	int		C;
	int		E;
	int		P;
	int		map_w;
	int		map_h;
	char	**map;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef	struct	s_player
{
	int	x;
	int	y;
}				t_player;


typedef	struct	s_data
{
	t_mlx		mlx;
	t_map		map;
	t_val		val;
	t_img		player;
	t_img		wall;
	t_img		bg;
	t_img		exit;
	t_img		collec;
	t_player	play;
	t_col		c;
	t_player	exit_pos;
}				t_data;

int			put_bg(t_data *data);
int			put_wall(t_data *data);
int			put_collec(t_data *data);
int			put_exit(t_data *data);
int			put_player(t_data *data);
int			move_down(t_data *data);
int			move_up(t_data *data);
int			move_right(t_data *data);
int			move_left(t_data *data);
int			check_map(t_data *data);
int			check_wall(t_data *data);
int			check_item(t_data *data);
int			check_rectangle(t_data *data);
int			cpy_map(t_data *data);
int			key_hook(int keycode, t_data *data);
void		set_item(char **map, int i, int k, t_data *data);
void		set_image(t_data *data);
void		set_1st_image(t_data *data);
void		set_player_pos(t_data *data);
void		set_exit_pos(t_data *data);
void		set_C_pos(t_data *data);
void		set_c_val(t_col *col, int i, int k);
void		init_collec(t_col **collec, t_data *data);
t_col		*ft_lstnewC();

#endif