/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:10:41 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/29 16:25:50 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int  ft_y_size(char *av)
{
    int     fd;
    int     count;
    int     byte;
    char    buf;

    fd = 0;
    count = 0;
    buf = 0;
    byte = 1;
    fd = open(av, O_RDONLY);
    while(byte > 0)
    {
        byte = read(fd, &buf, 1);
        if (buf == '\n')
            count++;
    }
    close(fd);
    return (count);
}

void map_init(t_map *map, char *av)
{
    map->y = ft_y_size(av);
    map_to_arr(map, av);
    map_arr_to_real(map);
}