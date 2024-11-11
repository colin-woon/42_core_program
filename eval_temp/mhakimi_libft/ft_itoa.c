/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:53:18 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/11 09:51:41 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * (1) ft_number_size returns the length of number 
 * so we can allocate memory later.
 *
 * (2) Find the length of number and assign it
 * to var length.
 *
 * (3) Allocate char type memory which is length + 
 * 1 for null terminator.
 *
 * (4) Guard malloc.
 *
 * (5) Assign value of n to long number (this type is important
 * to hold large values).
 *
 * (6) Check whether number is 0, or less (negative).
 *
 * (7) If neg, like putnbr, insert '-' at beginning, then
 * convert number to positive.
 *
 * (8) Then, gradually insert number + '0' to convert
 * int to ascii, into new_str.
 *
 * (9) Number % 10 to isolate single number to insert into new_str,
 * and Number / 10 to reduce the number for next iteration.
 *
 * (10) Return new_str.
*/

#include "libft.h"

static int	ft_number_size(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		length += 1;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	long	number;
	char	*new_str;

	length = ft_number_size(n);
	new_str = malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
		return (NULL);
	number = n;
	if (number == 0)
		new_str[0] = '0';
	else if (number < 0)
	{
		new_str[0] = '-';
		number = -number;
	}
	new_str[length] = '\0';
	while (number != 0)
	{
		new_str[length - 1] = (number % 10) + '0';
		number /= 10;
		length--;
	}
	return (new_str);
}

/*int main(void) {
    int numbers[] = {42, -42, 0, 2147483647, -2147483648};
    int i;

    for (i = 0; i < 5; i++) {
        char *str = ft_itoa(numbers[i]);
        printf("ft_itoa(%d) = \"%s\"\n", numbers[i], str);
        free(str);  // Assuming ft_itoa uses malloc, free the allocated memory
    }

    return 0;
}*/
