/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:17:30 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/09 11:59:10 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	ennemy_moves_x(t_data *data)
{
	if (data->ennemy_bol == 1)
	{
		if (data->map[data->ennemy_pos[1]][data->ennemy_pos[0] + 1] == '1')
		{
			data->ennemy_bol = 0;
			if (data->map[data->ennemy_pos[1]][data->ennemy_pos[0] - 1] == '1')
				return ;
			data->ennemy_pos[0] -= 1;
		}
		else
			data->ennemy_pos[0] += 1;
	}
	else if (data->ennemy_bol == 0)
	{
		if (data->map[data->ennemy_pos[1]][data->ennemy_pos[0] - 1] == '1')
		{
			data->ennemy_bol = 1;
			if (data->map[data->ennemy_pos[1]][data->ennemy_pos[0] + 1] == '1')
				return ;
			data->ennemy_pos[0] += 1;
		}
		else
			data->ennemy_pos[0] -= 1;
	}
}

void	ennemy_moves_y(t_data *data)
{
	if (data->ennemy_bole == 1)
	{
		if (data->map[data->ennemy_pos[1] + 1][data->ennemy_pos[0]] == '1')
		{
			data->ennemy_bole = 0;
			if (data->map[data->ennemy_pos[1] - 1][data->ennemy_pos[0]] == '1')
				return ;
			data->ennemy_pos[1] -= 1;
		}
		else
			data->ennemy_pos[1] += 1;
	}
	else if (data->ennemy_bole == 0)
	{
		if (data->map[data->ennemy_pos[1] - 1][data->ennemy_pos[0]] == '1')
		{
			data->ennemy_bole = 1;
			if (data->map[data->ennemy_pos[1] + 1][data->ennemy_pos[0]] == '1')
				return ;
			data->ennemy_pos[1] += 1;
		}
		else
			data->ennemy_pos[1] -= 1;
	}
}
