/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:54:02 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/07 12:03:49 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	right_d_key(t_data *data)
{
	if (data->map[data->player_pos[1]][data->player_pos[0] + 1] == '1')
		return (0);
	ennemy_moves_x(data);
	if (data->map[data->player_pos[1]][data->player_pos[0] + 1] == '0')
	{
		data->player_pos[0] += 1;
		data->moves_count += 1;
	}
	else if (data->map[data->player_pos[1]][data->player_pos[0] + 1] == 'C')
	{
		data->map[data->player_pos[1]][data->player_pos[0] + 1] = '0';
		data->c_collected += 1;
		data->player_pos[0] += 1;
		data->moves_count += 1;
	}
	else if (data->map[data->player_pos[1]][data->player_pos[0] + 1] == 'E')
	{
		data->moves_count += 1;
		data->player_pos[0] += 1;
		return (10);
	}
	return (1);
}

int	left_a_key(t_data *data)
{
	if (data->map[data->player_pos[1]][data->player_pos[0] - 1] == '1')
		return (0);
	ennemy_moves_x(data);
	if (data->map[data->player_pos[1]][data->player_pos[0] - 1] == '0')
	{
		data->player_pos[0] -= 1;
		data->moves_count += 1;
	}
	else if (data->map[data->player_pos[1]][data->player_pos[0] - 1] == 'C')
	{
		data->map[data->player_pos[1]][data->player_pos[0] - 1] = '0';
		data->c_collected += 1;
		data->player_pos[0] -= 1;
		data->moves_count += 1;
	}
	else if (data->map[data->player_pos[1]][data->player_pos[0] - 1] == 'E')
	{
		data->moves_count += 1;
		data->player_pos[0] -= 1;
		return (10);
	}
	return (1);
}

int	up_w_key(t_data *data)
{
	if (data->map[data->player_pos[1] - 1][data->player_pos[0]] == '1')
		return (0);
	ennemy_moves_y(data);
	if (data->map[data->player_pos[1] - 1][data->player_pos[0]] == '0')
	{
		data->player_pos[1] -= 1;
		data->moves_count += 1;
	}
	else if (data->map[data->player_pos[1] - 1][data->player_pos[0]] == 'C')
	{
		data->map[data->player_pos[1] - 1][data->player_pos[0]] = '0';
		data->c_collected += 1;
		data->player_pos[1] -= 1;
		data->moves_count += 1;
	}
	else if (data->map[data->player_pos[1] - 1][data->player_pos[0]] == 'E')
	{
		data->moves_count += 1;
		data->player_pos[1] -= 1;
		return (10);
	}
	return (1);
}

int	down_s_key(t_data *data)
{
	if (data->map[data->player_pos[1] + 1][data->player_pos[0]] == '1')
		return (0);
	ennemy_moves_y(data);
	if (data->map[data->player_pos[1] + 1][data->player_pos[0]] == '0')
	{
		data->player_pos[1] += 1;
		data->moves_count += 1;
	}
	else if (data->map[data->player_pos[1] + 1][data->player_pos[0]] == 'C')
	{
		data->map[data->player_pos[1] + 1][data->player_pos[0]] = '0';
		data->c_collected += 1;
		data->player_pos[1] += 1;
		data->moves_count += 1;
	}
	else if (data->map[data->player_pos[1] + 1][data->player_pos[0]] == 'E')
	{
		data->moves_count += 1;
		data->player_pos[1] += 1;
		return (10);
	}
	return (1);
}
