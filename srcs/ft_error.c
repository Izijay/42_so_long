/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:15:06 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/09 11:18:59 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(int err)
{
	if (err == 1)
		ft_putstr_fd("Error\nFailed to read map.\n", 2);
	else if (err == 2)
		ft_putstr_fd("Error\nMap file not found.\n", 2);
	else if (err == 3)
		ft_putstr_fd("Error\nOnly P, C, E, 0, and 1 accepted in map file.\n", 2);
	else if (err == 4)
		ft_putstr_fd("Error\nMap isn't retangular!\n", 2);
	else if (err == 5)
		ft_putstr_fd("Error\nOnly one player please.\n", 2);
	else if (err == 6)
		ft_putstr_fd("Error\nMemory allocation failed.\n", 2);
	else if (err == 7)
		ft_putstr_fd("Error\nYou must have at least One (1) collectible\n", 2);
	else if (err == 8)
		ft_putstr_fd("Error\nYou must have at least One (1) Exit\n", 2);
	else if (err == 9)
		ft_putstr_fd("Error\nFailed to load textures.\n", 2);
	else if (err == 10)
		ft_putstr_fd("Error\nNo empty line in map file please.\n", 2);
	return (0);
}
