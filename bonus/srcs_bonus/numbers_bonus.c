/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:50:47 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/06 14:58:08 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	nb_len(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	display_numbers(t_gbl *gbl)
{
	int	len;
	int	tmp;

	len = nb_len(gbl->data.moves_count) - 1;
	tmp = gbl->data.moves_count;
	if (gbl->data.moves_count > 999)
	{
		ft_putstr_fd("You LOSE !\nToo many moves.\n", 1);
		exit_echap_key(gbl);
	}
	while (len >= 0)
	{
		mlx_put_image_to_window(gbl->mlx.mlx_ptr, gbl->mlx.mlx_win,
			gbl->mlx.t_num_img[tmp % 10], len * 32, 0);
		tmp /= 10;
		len--;
	}
}
