#include "../../include/header.h"

/* static int  ft_x_size_arr(char *arr)
{

    int     count;
    int     byte;
    char    buf;

    count = 0;
    buf = 0;
    byte = 1;
    while(byte > 0)
    {
        byte = read(arr, &buf, 1);
        if (buf == '\n')
            break;
    }
    return (count);
} */


void map_to_arr(t_map *map, char *av)
{
    int     i;
    int     fd;
    int     j;
    char    *area;

    i = 0;
    j = 0;
    fd = open(av, O_RDONLY);
    map->map_dbl_arr = (char **)malloc(sizeof(char *) * (map->y + 1));
    area = get_next_line(fd);
    while(i < map->y + 1)
    {
        j = 0;
        if (area == NULL)
            break ;
        map->map_dbl_arr[i] = malloc((sizeof(char)*ft_strlen(area)) + 1);
        while (is_str_space(area) == -1 && area[j])
        {
            map->map_dbl_arr[i][j] = (char)area[j];
            j++;
        }
        free(area);
        area = get_next_line(fd);
        map->map_dbl_arr[i][j] = '\0';
        i++;
    }
    free(area);
    map->map_dbl_arr[i] = 0;
}