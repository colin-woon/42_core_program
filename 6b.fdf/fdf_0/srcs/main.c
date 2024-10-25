/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:52:54 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/25 14:32:18 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main()
{
	void *mlx_con;
	void *mlx_window;

	mlx_con = mlx_init();
	mlx_window = mlx_new_window(mlx_con, 500, 500, "testing window");

	ft_printf("%d", ft_strlen("hello"));
	mlx_pixel_put(mlx_con, mlx_window, 250, 250, 0x00ff00);
	mlx_loop(mlx_con);
}
