/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:46:01 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/09 09:13:45 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	exit_echap_key(t_gbl *gbl)
{
	mlx_destroy_image(gbl->mlx.mlx_ptr, gbl->mlx.mlx_img);
	mlx_destroy_window(gbl->mlx.mlx_ptr, gbl->mlx.mlx_win);
	ft_free_tab2d(gbl->data.map);
	exit(0);
}

void	ft_exit(t_gbl *gbl)
{
	if (gbl->data.c_collected != gbl->data.c_count)
		return ;
	printf("You WIN !\n");
	exit_echap_key(gbl);
}

int	cross_manager(t_gbl *gbl)
{
	exit_echap_key(gbl);
	return (1);
}

int	key_manager(int keycode, t_gbl *gbl)
{
	if (keycode == 2)
		if (right_d_key(&gbl->data) == 10)
			ft_exit(gbl);
	if (keycode == 0)
		if (left_a_key(&gbl->data) == 10)
			ft_exit(gbl);
	if (keycode == 13)
		if (up_w_key(&gbl->data) == 10)
			ft_exit(gbl);
	if (keycode == 1)
		if (down_s_key(&gbl->data) == 10)
			ft_exit(gbl);
	if (keycode == 53)
		exit_echap_key(gbl);
	return (1);
}
