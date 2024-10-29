/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiarr_errcln.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleow <bleow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:24:19 by bleow             #+#    #+#             */
/*   Updated: 2024/10/16 23:59:26 by bleow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_atoiarr_errcln is a function that converts a 2D array of strings into
an array of integers. Note that it will FREE the 2D array of strings after
conversion.
ONLY USE THIS FUNCTION IF YOU NO LONGER NEED THE 2D ARRAY OF STRINGS. 
OR IF THE 2D ARRAY OF STRINGS IS MALLOCCED AND YOU WANT TO FREE IT AFTER.
Designed to work with ft_atoierr() to handle errors.
*/

#include "libft.h"

static void	ft_error(char **temparr, int *intarr, int len);
int			*ft_atoiarr_errcln(char **temparr, int len);

static void	ft_error(char **temparr, int *intarr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(temparr[i++]);
	free(temparr);
	if (intarr != NULL)
		free(intarr);
	write(2, "Error\n", 6);
	exit(1);
}

int	*ft_atoiarr_errcln(char **temparr, int len)
{
	int			*intarr;
	int			i;
	long long	temp;

	len = ft_arrlen(temparr);
	intarr = malloc(len * sizeof(int));
	if (!intarr)
		ft_error(temparr, NULL, len);
	i = 0;
	while (i < len)
	{
		temp = ft_atoierr(temparr[i]);
		if (temp > INT_MAX || temp == INT_MIN)
			ft_error(temparr, intarr, len);
		intarr[i] = (int)temp;
		i++;
	}
	i = 0;
	while (i < len)
	{
		free(temparr[i]);
		i++;
	}
	free(temparr);
	return (intarr);
}
