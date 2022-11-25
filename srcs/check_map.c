/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:04:52 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/07 13:44:07 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extension(char *str, t_gbl *gbl)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
		&& str[i + 3] == 'r')
	{
		gbl->data.fd = open(str, O_RDONLY);
		if (gbl->data.fd == -1)
			return (ft_error(2));
		return (1);
	}
	else
		ft_putstr_fd("Error\nNot a valid extension.\n", 2);
	return (0);
}

int	invalid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'P' && str[i] != 'E'
			&& str[i] != 'C')
			return (ft_error(3));
		i++;
	}
	return (1);
}

int	wall_top_bot(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{
			ft_putstr_fd("Error\nTop or Bottom of map isn't a wall\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	wall_side(t_gbl *gbl)
{
	int	y;

	y = 1;
	while (y < gbl->data.y_max)
	{
		if (gbl->data.map[y][0] != '1'
			|| gbl->data.map[y][gbl->data.x_max - 1] != '1')
		{
			ft_putstr_fd("Error\nLeft or Right side isn't a wall\n", 2);
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_map(t_gbl *gbl)
{
	int	y;

	y = -1;
	gbl->data.y_max = ft_tablen(gbl->data.map) - 1;
	gbl->data.x_max = (int)ft_strlen(gbl->data.map[0]);
	if (wall_top_bot(gbl->data.map[0]) == 0)
		return (0);
	if (wall_top_bot(gbl->data.map[gbl->data.y_max]) == 0)
		return (0);
	while (gbl->data.map[++y])
	{
		if (wall_side(gbl) == 0)
			return (0);
		if ((int)ft_strlen(gbl->data.map[y]) != gbl->data.x_max)
			return (ft_error(4));
		if (!invalid_char(gbl->data.map[y]))
		{
			ft_free_tab2d(gbl->data.map);
			return (0);
		}
	}
	if (!parse_elements(gbl, 0, 0))
		return (0);
	return (1);
}
