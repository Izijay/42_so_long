/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:22:32 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/06 14:49:44 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	player_death(t_gbl *gbl)
{
	if (gbl->data.player_pos[0] == gbl->data.ennemy_pos[0]
		&& gbl->data.player_pos[1] == gbl->data.ennemy_pos[1])
	{
		ft_putstr_fd("You LOSE !\n", 1);
		exit_echap_key(gbl);
	}
}

void	anim_c(t_gbl *gbl, int x, int y)
{
	static int	i = 0;

	if (i < 50)
		mlx_put_image_to_window(gbl->mlx.mlx_ptr,
			gbl->mlx.mlx_win, gbl->mlx.txt_img[1], x * 32, y * 32);
	else if (i >= 50 && i < 100)
		mlx_put_image_to_window(gbl->mlx.mlx_ptr,
			gbl->mlx.mlx_win, gbl->mlx.txt_img[6], x * 32, y * 32);
	else if (i >= 100)
	{
		i = 0;
		return ;
	}
	i++;
}

void	ft_draw_elements(t_gbl *gbl, int x, int y)
{
	if (x == gbl->data.player_pos[0] && y == gbl->data.player_pos[1])
	{
		mlx_put_image_to_window(gbl->mlx.mlx_ptr,
			gbl->mlx.mlx_win, gbl->mlx.txt_img[4], x * 32, y * 32);
		mlx_put_image_to_window(gbl->mlx.mlx_ptr,
			gbl->mlx.mlx_win, gbl->mlx.txt_img[3], x * 32, y * 32);
	}
	if (x == gbl->data.ennemy_pos[0] && y == gbl->data.ennemy_pos[1])
	{
		mlx_put_image_to_window(gbl->mlx.mlx_ptr,
			gbl->mlx.mlx_win, gbl->mlx.txt_img[4], x * 32, y * 32);
		mlx_put_image_to_window(gbl->mlx.mlx_ptr,
			gbl->mlx.mlx_win, gbl->mlx.txt_img[5], x * 32, y * 32);
	}
	if (gbl->data.map[y][x] == 'E')
		mlx_put_image_to_window(gbl->mlx.mlx_ptr,
			gbl->mlx.mlx_win, gbl->mlx.txt_img[2], x * 32, y * 32);
	if (gbl->data.map[y][x] == 'C')
	{
		mlx_put_image_to_window(gbl->mlx.mlx_ptr,
			gbl->mlx.mlx_win, gbl->mlx.txt_img[4], x * 32, y * 32);
		anim_c(gbl, x, y);
	}
}

int	ft_draw_map(t_gbl *gbl)
{
	int	x;
	int	y;

	y = 0;
	player_death(gbl);
	while (y <= gbl->data.y_max)
	{
		x = 0;
		while (x <= gbl->data.x_max)
		{
			if (gbl->data.map[y][x] == '1')
				mlx_put_image_to_window(gbl->mlx.mlx_ptr,
					gbl->mlx.mlx_win, gbl->mlx.txt_img[0], x * 32, y * 32);
			if (gbl->data.map[y][x] == '0')
				mlx_put_image_to_window(gbl->mlx.mlx_ptr,
					gbl->mlx.mlx_win, gbl->mlx.txt_img[4], x * 32, y * 32);
			ft_draw_elements(gbl, x, y);
			display_numbers(gbl);
			x++;
		}
		y++;
	}
	return (1);
}
