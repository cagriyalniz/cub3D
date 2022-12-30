#include "../../include/header.h"

int main(int ac, char **av)
{
    if (ac == 2 && map_name_check(av[1]) == 1)
    {
        printf("map_name: %s\n", av[1]);
        t_map *map = malloc(sizeof(t_map));
        //init
        map_init(map, av[1]);
        printf("y: %d\n", map->y);
        //map_fix(map);
        if (map_check(map) == -1)
            printf("ERROR: %s\n", map->error_msg);

    }
    else
    {
        printf("wrong name: %s\n", av[1]);
    }
}