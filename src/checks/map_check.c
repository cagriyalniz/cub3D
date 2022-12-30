#include "../../include/header.h"

int map_name_check(char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    i--;
    while(s[i] != '.' && s[i])
        i--;
    i++;
    if (ft_strnstr("cub", &s[i], 3) && s[i + 3] == '\0')
        return 1;
    return 0;
}

static int map_zero_check(t_map *map, int i, int j)
{
    if (map->map_real[i][j + 1] && map->map_real[i][j + 1] <= 32)
        return (-1);
    else if (map->map_real[i][j - 1] && map->map_real[i][j - 1] <= 32)
        return (-1);
    else if (map->map_real[i + 1][j] && map->map_real[i + 1][j] <= 32)
        return (-1);
    else if (map->map_real[i - 1][j] && map->map_real[i - 1][j] <= 32)
        return (-1);
    return (0);
}

int map_wall_check(t_map *map)
{
    int i;
    int j;

    i = 6;
    while (map->map_real[i])
    {
        j = 0;
        while(map->map_real[i][j])
        {
            if (map->map_real[i][j] == '0')
            {
                if (map_zero_check(map, i, j) == -1)
                    return -1;
            }
            j++;
        }
        i++;
    }

    return (1);
}

static int	is_direction(char c)
{
	char *ar;

	ar = "WNSE";//free ?
	if (ft_strchr(ar, c) != 0 || (c == '1' || c == '0' || c == 32 || c == '\n'))
		return (0);
	return (-1);
}

static int map_character_check(t_map *map)
{
    int i;
    int	j;

	i = 0;
	j = 0;
	while(map->map_real[++i])
    {
        if (map->map_real[i][0] <= 32)
            break ;
    }
	while(map->map_real[i])
	{
		j = 0;
		while(map->map_real[i][j])
		{
			if (is_direction(map->map_real[i][j]) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int map_player_check(t_map *map)
{
    int i;
    int	j;
    int player;

	i = 6;
	j = 0;
    player = 0;
	while(map->map_real[i][0] <= 32)
        i++;
	while(map->map_real[i])
	{
		j = 0;
		while(map->map_real[i][j])
		{
			if (ft_strchr("WSNE", map->map_real[i][j]) != 0)
			    player++;
			j++;
		}
		i++;
	}
    if (player != 1)
        return (-1);
    return (0);
}


int map_check(t_map *map)
{
    if (map_wall_check(map) == -1)
    {
        map->error_msg = "Wall problem";
        return (-1);
    }
    if (map_character_check(map) == -1)
    {
        map->error_msg = "invalid character";
        return (-1);
    }
    if (map_player_check(map) == -1)
    {
        map->error_msg = "Player count is wrong";
        return -1;
    }
    return 1;
}