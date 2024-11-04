/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:25:53 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/31 17:26:22 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_files *files);
void	launch_here_doc(t_files *files);

/* 
- 0644 necessary to specify as CREATE is used, grants READ & WRITE 
- No difference between doing infile or outfile logic first
Mandatory: Open and save infile FD & outfile FD
Bonus: SAME but also launches here_doc
*/
void	open_files(t_files *files)
{
	files->out_fd = -1;
	files->in_fd = -1;
	if ((!files->out_f_ko && !files->out_w_ko) || files->out_f_ko)
	{
		if (!files->is_here_doc)
			files->out_fd = open(files->outfile, \
			O_TRUNC | O_WRONLY | O_CREAT, 0644);
		else if (files->is_here_doc)
			files->out_fd = open(files->outfile, \
			O_APPEND | O_WRONLY | O_CREAT, 0644);
	}
	files->out_f_ko = access(files->outfile, F_OK);
	files->out_w_ko = access(files->outfile, W_OK);
	if (!files->is_here_doc && !files->in_f_ko && !files->in_r_ko)
		files->in_fd = open(files->infile, O_RDONLY);
	if (files->is_here_doc)
	{
		files->in_fd = open("/tmp/.here_doc.txt", O_WRONLY | O_CREAT, 0644);
		launch_here_doc(files);
		close(files->in_fd);
		files->in_fd = open("/tmp/.here_doc.txt", O_RDONLY);
	}
}
/* 
Launch heredoc to receive input from user, 
then stores it in the created file earlier
(.here_doc.txt)
 */
void	launch_here_doc(t_files *files)
{
	char	*line;
	char	*data;

	data = ft_strdup("");
	if (data == NULL)
		return ;
	while (1)
	{
		ft_putstr_fd("here_doc >", 1);
		line = get_next_line(0);
		if (line == NULL)
			return (free(data));
		if (!ft_strncmp(line, files->limiter, ft_strlen(files->limiter)))
		{
			if (ft_strlen(line) == ft_strlen(files->limiter) + 1)
				break ;
		}
		data = strj(data, line);
		if (data == NULL)
			return ;
	}
	write(files->in_fd, data, ft_strlen(data));
	return (free(line), free(data));
}
