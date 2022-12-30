#include "../../include/header.h"

void put_map(t_map *map)
{
    int i;

    i = 0;
    while(map->map_dbl_arr[i])
    {
        printf("%d %s",i, map->map_dbl_arr[i]);
        i++;
    }
    printf("\n");
}

int is_str_space(char *s)
{
    int	i;
	int	count;

	i = 0;
	count = 0;
	while(s[i])
	{
		if (s[i] <= 32)
			count++;
		i++;
	}
	if ((int)ft_strlen(s) == count)
		return (1);
	return (-1);
}