/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:49:41 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/12 17:05:05 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <libft.h>
# include <ft_printf.h>

typedef struct s_lists
{
	int				x;
	int				y;
	int				val;
	struct s_lists	*next;
}				t_lists;

typedef struct s_val
{
	int	i;
	int	k;
	int	j;
}				t_val;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map
{
	int		c;
	int		e;
	int		p;
	int		map_w;
	int		map_h;
	char	**map;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	t_map		tmap;
	t_val		val;
	t_img		player;
	t_img		wall;
	t_img		bg;
	t_img		exit;
	t_img		collec;
	t_pos		play;
	t_lists		c;
	t_lists		f;
	t_pos		exit_pos;
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
int			check_map(t_data *data, char *av);
int			check_wall(t_data *data);
int			check_item(t_data *data);
int			check_rectangle(t_data *data);
int			cpy_map(t_data *data, char *av);
int			key_hook(int keycode, t_data *data);
int			check_if_finish(t_data *data, char *av);
int			check_fin(t_lists *f, t_data *data);
int			check_exit(t_lists **f, t_data *data);
int			check_road(t_lists **f, t_data *data);
int			move(t_data *data, t_lists **f, int x, int y);
int			cpy_tmap(t_data *data, char *av);
int			alloc_tmap(t_data *data, char *av);
void		print_gg(void);
int			rm_nl(t_data *data);
int			check_char(t_data *data);
int			alloc_map(t_data *data, char *av);
void		destroy_image(t_data *data);
int			close_win(int keycode, t_data *data);
int			close_winx(t_data *data);
void		set_f_pos(t_lists *f, t_data *data);
void		check_col(char c, t_data *data);
void		lstadd_front(t_lists **lst);
void		delfront(t_lists **f);
void		ft_error(t_data *data, int x);
void		move_count(void);
int			mlx_main(t_data *data);
void		set_item(char **map, int i, int k, t_data *data);
void		set_image(t_data *data);
void		set_1st_image(t_data *data);
void		set_player_pos(t_data *data);
void		set_exit_pos(t_data *data);
void		set_c_pos(t_data *data);
void		set_c_val(t_lists *col, int i, int k);
void		init_collec(t_lists **collec, t_data *data);
t_lists		*ft_lstnewc(void);

#endif