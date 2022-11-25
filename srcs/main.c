/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:39:57 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/09 10:39:54 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	texture_load(t_gbl *gbl)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(PATH, ' ');
	if (tab == NULL)
		return (1);
	while (i < 5)
	{
		gbl->mlx.txt_img[i] = mlx_xpm_file_to_image(gbl->mlx.mlx_ptr,
				tab[i], &gbl->mlx.txt_x[i], &gbl->mlx.txt_y[i]);
		if (!gbl->mlx.txt_img[i])
		{
			ft_free_tab2d(gbl->data.map);
			ft_free_tab2d(tab);
			return (ft_error(9));
		}
		i++;
	}
	ft_free_tab2d(tab);
	return (1);
}

int	start_game(t_gbl *gbl)
{
	gbl->mlx.mlx_ptr = mlx_init();
	if (gbl->mlx.mlx_ptr == NULL)
	{
		ft_free_tab2d(gbl->data.map);
		return (0);
	}
	if (!texture_load(gbl))
		return (0);
	gbl->mlx.mlx_win = mlx_new_window(gbl->mlx.mlx_ptr,
			gbl->data.x_max * 32, (gbl->data.y_max + 1) * 32, "so_long");
	gbl->mlx.mlx_img = mlx_new_image(gbl->mlx.mlx_ptr,
			gbl->data.x_max * 32, (gbl->data.y_max + 1) * 32);
	mlx_hook(gbl->mlx.mlx_win, 2, 1L << 0, key_manager, gbl);
	mlx_hook(gbl->mlx.mlx_win, 17, 1L << 2, cross_manager, gbl);
	mlx_loop_hook(gbl->mlx.mlx_ptr, ft_draw, gbl);
	mlx_loop(gbl->mlx.mlx_ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_gbl	gbl;

	gbl.data.c_count = 0;
	gbl.data.moves_count = 0;
	gbl.data.c_collected = 0;
	gbl.data.p_count = 0;
	gbl.data.e_count = 0;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nOnly one argument please.\n", 2);
		return (1);
	}
	if (!check_extension(av[1], &gbl))
		return (1);
	if (!map_to_tab2d(&gbl))
		return (1);
	if (!start_game(&gbl))
		return (1);
	return (0);
}
