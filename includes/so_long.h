/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:17:36 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/07 14:09:08 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PATH "tx/w.xpm tx/c.xpm tx/e.xpm tx/p.xpm tx/f.xpm"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_data
{
	int		fd;
	char	**map;
	int		x_max;
	int		y_max;
	int		p_count;
	int		c_count;
	int		e_count;
	int		player_pos[2];
	int		c_collected;
	int		moves_count;
}	t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	void	*txt_img[5];
	int		txt_x[5];
	int		txt_y[5];
}	t_mlx;

typedef struct s_gbl
{
	struct s_data	data;
	struct s_mlx	mlx;
}	t_gbl;

int	check_extension(char *str, t_gbl *gbl);
int	check_map(t_gbl *gbl);
int	ft_error(int err);
int	parse_elements(t_gbl *gbl, int x, int y);
int	ft_draw(t_gbl *gbl);
int	map_to_tab2d(t_gbl *gbl);
int	key_manager(int keycode, t_gbl *gbl);
int	cross_manager(t_gbl *gbl);
int	right_d_key(t_data *data);
int	left_a_key(t_data *data);
int	up_w_key(t_data *data);
int	down_s_key(t_data *data);

#endif
