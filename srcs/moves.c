/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:54:02 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/06 09:57:04 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	right_d_key(t_data *data)
{
	if (data->map[data->player_pos[1]][data->player_pos[0] + 1] == '1')
		return (0);
	if (data->map[data->player_pos[1]][data->player_pos[0] + 1] == '0')
	{
		data->player_pos[0] += 1;
		data->moves_count += 1;
		printf("Move N°: %d\n", data->moves_count);
	}
	else if (data->map[data->player_pos[1]][data->player_pos[0] + 1] == 'C')
	{
		data->map[data->player_pos[1]][data->player_pos[0] + 1] = '0';
		data->c_collected += 1;
		data->player_pos[0] += 1;
		data->moves_count += 1;
		printf("Move N°: %d\n", data->moves_count);
	}
	else if (data->map[data->player_pos[1]][data->player_pos[0] + 1] == 'E')
	{
		data->moves_count += 1;
		data->player_pos[0] += 1;
		printf("Move N°: %d\n", data->moves_count);
		return (10);
	}
	return (1);
}

int	left_a_key(t_data *data)
{
	if (data->map[data->player_pos[1]][data->player_pos[0] - 1] == '1')
		return (0);
	if (data->map[data->player_pos[1]][data->player_pos[0] - 1] == '0')
	{
		data->player_pos[0] -= 1;
		data->moves_count += 1;
		printf("Move N°: %d\n", data->moves_count);
	}
	else if (data->map[data->player_pos[1]][data->player_pos[0] - 1] == 'C')
	{
		data->map[data->player_pos[1]][data->player_pos[0] - 1] = '0';
		data->c_collected += 1;
		data->player_pos[0] -= 1;
		data->moves_count += 1;
		printf("Move N°: %d\n", data->moves_count);
	}
	else if (data->map[data->player_pos[1]][data->player_pos[0] - 1] == 'E')
	{
		data->moves_count += 1;
		data->player_pos[0] -= 1;
		printf("Move N°: %d\n", data->moves_count);
		return (10);
	}
	return (1);
}

int	up_w_key(t_data *data)
{
	if (data->map[data->player_pos[1] - 1][data->player_pos[0]] == '1')
		return (0);
	if (data->map[data->player_pos[1] - 1][data->player_pos[0]] == '0')
	{
		data->player_pos[1] -= 1;
		data->moves_count += 1;
		printf("Move N°: %d\n", data->moves_count);
	}
	else if (data->map[data->player_pos[1] - 1][data->player_pos[0]] == 'C')
	{
		data->map[data->player_pos[1] - 1][data->player_pos[0]] = '0';
		data->c_collected += 1;
		data->player_pos[1] -= 1;
		data->moves_count += 1;
		printf("Move N°: %d\n", data->moves_count);
	}
	else if (data->map[data->player_pos[1] - 1][data->player_pos[0]] == 'E')
	{
		data->moves_count += 1;
		data->player_pos[1] -= 1;
		printf("Move N°: %d\n", data->moves_count);
		return (10);
	}
	return (1);
}

int	down_s_key(t_data *data)
{
	if (data->map[data->player_pos[1] + 1][data->player_pos[0]] == '1')
		return (0);
	if (data->map[data->player_pos[1] + 1][data->player_pos[0]] == '0')
	{
		data->player_pos[1] += 1;
		data->moves_count += 1;
		printf("Move N°: %d\n", data->moves_count);
	}
	else if (data->map[data->player_pos[1] + 1][data->player_pos[0]] == 'C')
	{
		data->map[data->player_pos[1] + 1][data->player_pos[0]] = '0';
		data->c_collected += 1;
		data->player_pos[1] += 1;
		data->moves_count += 1;
		printf("Move N°: %d\n", data->moves_count);
	}
	else if (data->map[data->player_pos[1] + 1][data->player_pos[0]] == 'E')
	{
		data->moves_count += 1;
		data->player_pos[1] += 1;
		printf("Move N°: %d\n", data->moves_count);
		return (10);
	}
	return (1);
}
