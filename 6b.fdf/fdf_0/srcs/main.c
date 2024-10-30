/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:52:54 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/30 17:38:03 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_putendl_fd("Correct args: ./fdf <MAPFILE>", 2);
		return (ARG_ERROR);
	}
	if (parse_file(&data, av[1]) == -1)
		return (FILE_ERROR);
	generate_map(&data);
	generate_iso_view(data.map);
	autoscale(data.map);
	data.animate_on = 0;
	print_map(data.map);
	// print_img(&data.img);
	print_pt(data.map->points);
	print_data(&data);
	if (start_mlx(&data) == -1)
		return (MLX_ERROR);
	return (0);
}
