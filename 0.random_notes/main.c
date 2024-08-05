#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <limits.h>

typedef struct s_dict
{
	void	(*func)(int fd);
	char	*key;
}	t_dict;

void	open_func(int fd)
{
	ft_putendl_fd("open", fd);
}

void	close_func(int fd)
{
	ft_putendl_fd("close", fd);
}
// have a list of str you to compare and do something
int	main(int ac , char **av)
{
	// unsigned int i = -1;
	// printf("%u %u\n", i, ++i);
	// int	n = INT_MAX;
	// printf("%d %d\n", n, ++n);
	int		i;
	t_dict	*d;

	if (ac != 2)
	{
		printf("Opps\n");
		return (1);
	}
	int	fd = open("test.txt", O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
	{
		printf("something wrong\n");
		return (1);
	}
	printf("fd num %d\n", fd);
	d = (t_dict[3]){(t_dict){.key = "OPEN", .func = &open_func},
		(t_dict){ .key = "CLOSE", .func = &close_func}, (t_dict){0}};
	i = -1;
	while (d[++ i].key)
	{
		if (!ft_strncmp(av[1], d[i].key, ft_strlen(d[i].key)))
			d[i].func(fd);
	}
	close(fd);
	// return (0);
}

void	ref(void) // cspduixX
{
	if (s[i] == '%')
	{
		s[i + 1] == c ? s ? d ?
	}
}
// int	main(void)
{
	char	*s = "lulz";
	char	s[] = "lulz";
}
