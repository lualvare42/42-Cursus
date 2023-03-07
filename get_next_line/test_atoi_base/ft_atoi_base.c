#include <stdio.h>

int ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;
	int	n;
	
	sign = 1;
	n = 0;
	if (str[n] == '-')
	{
		sign = -1;
		n++;
	}
	result = 0;
	while (str[n])
	{
		result *= str_base;
		if ((str[n] >= 48) && (str[n] <= 57))
			result += str[n] - 48;
		else if ((str[n] >= 65) && (str[n] <= 70))
			result += str[n] - 55;
		else if ((str[n] >= 97) && (str[n] <= 102))
			result += str[n] - 87;
		else
			return (result * sign);
		n++;
	}
	return (result * sign);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.", 16));
	printf("%d\n", ft_atoi_base("B", 16));
	printf("%d\n", ft_atoi_base("C", 16));
	printf("%d\n", ft_atoi_base("D", 16));
	printf("%d\n", ft_atoi_base("e", 16));
	printf("%d\n", ft_atoi_base("E", 16));
	return (0);
}
