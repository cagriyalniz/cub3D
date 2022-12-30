#include "../../include/header.h"

static int map_real_size(t_map *map)
{
    int	i;
	int	count;

	i = 0;
	count = 0;
	while(map->map_dbl_arr[i])
	{
		if (is_str_space(map->map_dbl_arr[i]) == -1)
			count++;
		i++;
	}
	return (count);
}

void map_arr_to_real(t_map *map)
{
    int size;
    int i;
    int	j;

	i = 0;
	j = 0;
    size = map_real_size(map);
	map->map_real = malloc(sizeof(char *)*size + 1);
	while(map->map_dbl_arr[i])
	{
		if (is_str_space(map->map_dbl_arr[i]) == -1)
		{
			map->map_real[j] = map->map_dbl_arr[i];
			j++;
		}
		i++;
	}
}