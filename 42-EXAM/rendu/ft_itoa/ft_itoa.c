#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int count_nbr_len(int nbr)
{
	int len = 0;
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return len;
}

char	*ft_itoa(int nbr)
{
	int word_len = 0;
	char *digits = 0;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	word_len = count_nbr_len(nbr);
	digits = malloc(word_len + 1);
	if (digits == NULL)
		return NULL;
	digits[word_len] = '\0';
	if (nbr == 0)
	{
		digits[0] = '0';
		return (digits);
	}
	if (nbr < 0)
	{
		digits[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		digits[--word_len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (digits);
}

/* int main ()
{
	printf("%s", ft_itoa(23452343));
} */
