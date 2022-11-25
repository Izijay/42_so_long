/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:22:32 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/09 09:41:07 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_elements(t_gbl *gbl, int x, int y)
{
	if (gbl->data.map[y][x] == 'C')
	{
		mlx_put_image_to_window(gbl->mlx.mlx_ptr, gbl->mlx.mlx_win,
			gbl->mlx.txt_img[4], x * 32, y * 32);
		mlx_put_image_to_window(gbl->mlx.mlx_ptr, gbl->mlx.mlx_win,
			gbl->mlx.txt_img[1], x * 32, y * 32);
	}
	if (gbl->data.map[y][x] == 'E')
		mlx_put_image_to_window(gbl->mlx.mlx_ptr, gbl->mlx.mlx_win,
			gbl->mlx.txt_img[2], x * 32, y * 32);
	if (x == gbl->data.player_pos[0] && y == gbl->data.player_pos[1])
	{
		mlx_put_image_to_window(gbl->mlx.mlx_ptr, gbl->mlx.mlx_win,
			gbl->mlx.txt_img[4], x * 32, y * 32);
		mlx_put_image_to_window(gbl->mlx.mlx_ptr, gbl->mlx.mlx_win,
			gbl->mlx.txt_img[3], x * 32, y * 32);
	}
}

int	ft_draw(t_gbl *gbl)
{
	int	x;
	int	y;

	y = 0;
	while (y <= gbl->data.y_max)
	{
		x = 0;
		while (x <= gbl->data.x_max)
		{
			if (gbl->data.map[y][x] == '1')
				mlx_put_image_to_window(gbl->mlx.mlx_ptr, gbl->mlx.mlx_win,
					gbl->mlx.txt_img[0], x * 32, y * 32);
			if (gbl->data.map[y][x] == '0')
				mlx_put_image_to_window(gbl->mlx.mlx_ptr, gbl->mlx.mlx_win,
					gbl->mlx.txt_img[4], x * 32, y * 32);
			ft_draw_elements(gbl, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
