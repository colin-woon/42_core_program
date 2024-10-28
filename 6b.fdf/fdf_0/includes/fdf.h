/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:23:55 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/28 18:46:39 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include <math.h>
#include <fcntl.h>

#define ARG_ERROR -1
#define MALLOC_ERROR 1
#define FILE_ERROR -1
#define MLX_ERROR -1

# define WIN_W	1280
# define WIN_H	720
# define RED	0x00FF0000
# define DRED	0x00660000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define DBLUE	0x00000066
# define PURPLE	0x00B491C8
# define WHITE	0x00FFFFFF
# define DGREEN	0x00006600
# define BLACK	0x00000000
# define GREY	0x00888888
# define DGREY	0x00333333
# define GROUND_COLOUR	RED
# define HIGH_COLOUR	PURPLE
# define LOW_COLOUR		DBLUE
// # define ISO	0.6154

typedef struct s_img
{
	void	*buffer;
	char	*address;
	int		bits_p_pixel;
	int		line_len;
	int		endian;
}	t_img;


typedef struct s_pt
{
	float_t	x;
	float_t	y;
	float_t	z;
	int		colour;
}	t_pt;

// pt_arr = points
// x_dim = width
// y_dim = height
// min_z = min_height
// max_z = max_height
// base_i = basis_x
// base_j = basis_y
// base_k = basis_z
typedef struct s_map
{
	t_pt	*points;
	int		width;
	int		height;
	int		point_gap;
	int		min_z;
	int		max_z;
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
	t_pt	basis_x;
	t_pt	basis_y;
	t_pt	basis_z;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_img	img;
	t_map	*map;
	char	**parsed_file;
	int		animate_on;
	t_map	*origin_map;
}	t_data;

// Utils Colour
int		get_height_gradient_colour(t_pt cur, t_pt start, t_pt end);
float_t	get_percentage(int start, int end, int cur);
int		get_colour_channel(int start, int end, float_t percentage);

// Utils Parser
void	newline_to_space(unsigned int i, char *s);
int		is_map_valid(int new_columns, t_data *previous);
void	append_line_to_file(char **line, char **file);

// Parser
int		parse_file(t_data *data, char *filename);
char	*get_file(int fd, t_data *data);
int		count_columns(char *line);

// Generate Map
t_map	*generate_map(t_data *data);
void	fill_map(t_data *data, t_map *map);
void	set_height_range(t_map *map, t_pt *current);
void	set_point_colours(t_map *map);
t_map	*save_original_map(t_data *data);

