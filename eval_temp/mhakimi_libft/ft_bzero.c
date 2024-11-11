/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:16:19 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/11 09:43:12 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * bzero specify number of bytes in memory to 0
 *
 */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}

/*int main(void) {
    char buffer[10] = "Hello123";

    printf("Before ft_bzero: \"%s\"\n", buffer);

    // Call ft_bzero on the first 5 bytes of the buffer
    ft_bzero(buffer, 5);

    // Print each byte in buffer to see if ft_bzero worked correctly
    printf("After ft_bzero (first 5 bytes): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]); // Will print 0 for bytes cleared by ft_bzero
    }
    printf("\n");

    return 0;
}*/
