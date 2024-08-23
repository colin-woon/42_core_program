/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:38:36 by cwoon             #+#    #+#             */
/*   Updated: 2024/06/10 19:10:41 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Changes uppercase character to lowercase
Input: ASCII code `c`, presumably uppercase characters
Output: ASCII code `c`
Increments `c` with 32 to get its lowercase counterpart if
uppercase letters are detected.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
