#include "../../include/header.h"
/*
C 225,30,0
EA ./path_to_the_east_texture
F 220,100,0
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
*/

/* static void map_fix_swap(char **map, int j, int i)
{
	char *tmp;

	tmp = map[i];
	map[i] = map[j];
	map[j] = tmp;
}

static int is_sort_map(char **map)
{
	if (map[0][0] == 'N' && map[1][0] == 'S' && map[2][0] == 'W' && map[3][0] == 'E' && map[4][0] == 'F' && map[5][0] == 'C')
		return (1);
	return (-1);
} */

#include <string.h>
void map_fix(t_map *map)
{
	(void)map;
}