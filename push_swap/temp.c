int	count_num(char *str)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	while (*str)
	{
		if (*str == '-')
			str++;
		if (*str >= '0' && *str <= '9' && flag)
		{
			while (*str >= '0' && *str <= '9')
				str++;
			i += 1;
			flag = 0;
		}
		else
		{
			flag = 1;
			str++;
		}
	}
	return (i);
}