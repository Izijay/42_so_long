/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:59:27 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/09 11:58:16 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	verif_elements(t_gbl *gbl)
{
	if (gbl->data.p_count > 1 || gbl->data.p_count < 1)
		return (ft_error(5));
	if (gbl->data.c_count == 0)
		return (ft_error(7));
	if (gbl->data.e_count < 1)
		return (ft_error(8));
	return (1);
}

int	parse_ennemy(t_gbl *gbl, int y)
{
	int	x;

	while (gbl->data.map[++y])
	{
		x = -1;
		while (gbl->data.map[y][++x])
		{
			if (gbl->data.map[y][x] == '0'
				&& (gbl->data.map[y][x + 1] == '0'
					|| gbl->data.map[y][x - 1] == '0'
						|| gbl->data.map[y + 1][x] == '0'
							|| gbl->data.map[y - 1][x] == '0'))
			{
				if (x != gbl->data.player_pos[0]
					&& gbl->data.player_pos[1] != y)
				{	
					gbl->data.ennemy_pos[0] = x;
					gbl->data.ennemy_pos[1] = y;
					return (1);
				}
			}
		}
	}
	return (ft_error(11));
}

int	parse_elements(t_gbl *gbl, int x, int y)
{
	while (gbl->data.map[++y])
	{
		x = 0;
		while (gbl->data.map[y][++x])
		{
			if (gbl->data.map[y][x] == 'C')
				gbl->data.c_count++;
			if (gbl->data.map[y][x] == 'E')
				gbl->data.e_count++;
			if (gbl->data.map[y][x] == 'P')
			{
				gbl->data.p_count++;
				gbl->data.player_pos[0] = x;
				gbl->data.player_pos[1] = y;
				gbl->data.map[y][x] = '0';
			}
		}
	}
	if (!verif_elements(gbl))
		return (0);
	return (1);
}

void	check_buff_len(t_gbl *gbl, int ret)
{
	if (ret == -1)
	{
		close(gbl->data.fd);
		ft_error(1);
		exit(1);
	}
	if (ret > 4999)
	{
		close(gbl->data.fd);
		ft_putstr_fd("Error\nMap is too big.\n", 2);
		exit(1);
	}
}

int	map_to_tab2d(t_gbl *gbl)
{
	char	buff[5000];
	int		i;
	int		ret;

	i = -1;
	ft_bzero(buff, 5000);
	ret = read(gbl->data.fd, buff, 5000);
	check_buff_len(gbl, ret);
	close(gbl->data.fd);
	while (buff[++i])
		if (buff[i] == '\n' && buff[i + 1] == '\n')
			return (ft_error(10));
	gbl->data.map = ft_split(buff, '\n');
	if (gbl->data.map == NULL)
		return (ft_error(6));
	if (!check_map(gbl))
		return (0);
	if (!parse_ennemy(gbl, -1))
		return (0);
	return (1);
}
