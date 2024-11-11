/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:54:22 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/11 09:36:52 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Function taking ascii (const char *) and returns integer (int)
 *
 * Input must be in acceptable format [whitespace][signs][number]
 *
 * (1) Skip white spaces
 *
 * (2) If negative sign, sign = -1;
 *
 * (3) Accumulate ascii to integer form by * 10 - '0'
 *
 * (4) Return sign * result
 *
 */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

/*int main(void) {
    // Test cases for ft_atoi
    const char *test_cases[] = {
        "42",
        "   -42",
        "+42",
        "2147483647",    // Max int
        "-2147483648",   // Min int
        "0",
        "   123abc456",  // Numbers followed by letters
        "abc123",        // Letters before numbers
        "",
        "   -0",
        "   +0",
    };
    
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    for (int i = 0; i < num_cases; i++) {
        printf("ft_atoi(\"%s\") = %d\n", test_cases[i], ft_atoi(test_cases[i]));
    }

    return 0;
}*/
