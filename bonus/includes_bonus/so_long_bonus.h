/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:17:36 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/07 14:33:29 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define PATH "tx/w.xpm tx/c.xpm tx/e.xpm tx/p.xpm tx/f.xpm tx/m.xpm tx/a.xpm"
# define NUM "tx/0.xpm tx/1.xpm tx/2.xpm tx/3.xpm tx/4.xpm tx/5.xpm " 
# define NUM2 "tx/6.xpm tx/7.xpm tx/8.xpm tx/9.xpm"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../../libft/libft.h"
# include "../../minilibx/mlx.h"

typedef struct s_data
{
	int		fd;
	char	**map;
	char	*num;
	int		x_max;
	int		y_max;
	int		p_count;
	int		c_count;
	int		e_count;
	int		player_pos[2];
	int		ennemy_pos[2];
	int		c_collected;
	int		moves_count;
	int		ennemy_bol;
	int		ennemy_bole;
}	t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	void	*txt_img[7];
	int		txt_x[7];
	int		txt_y[7];
	void	*t_num_img[10];
	int		t_num_x[10];
	int		t_num_y[10];
}	t_mlx;

typedef struct s_gbl
{
	struct s_data	data;
	struct s_mlx	mlx;
}	t_gbl;

int		check_extension(char *str, t_gbl *gbl);
int		check_map(t_gbl *gbl);
int		ft_error(int err);
int		parse_elements(t_gbl *gbl, int x, int y);
int		ft_draw_map(t_gbl *gbl);
int		map_to_tab2d(t_gbl *gbl);
int		key_manager(int keycode, t_gbl *gbl);
int		cross_manager(t_gbl *gbl);
int		right_d_key(t_data *data);
int		left_a_key(t_data *data);
int		up_w_key(t_data *data);
int		down_s_key(t_data *data);
int		exit_echap_key(t_gbl *gbl);
void	display_numbers(t_gbl *gbl);
void	ennemy_moves_x(t_data *data);
void	ennemy_moves_y(t_data *data);

#endif
