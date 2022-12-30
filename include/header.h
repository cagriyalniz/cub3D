#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

# include "../libft/libft.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

typedef struct s_map
{
    int     x;
    int     y;
    char    **map_dbl_arr;
    char    **map_real;
    char    *error_msg;
	char	*e_path;
	char	*n_path;
	char	*w_path;
	char	*s_path;
}t_map;


//map
void	map_init(t_map *map, char *av);
void	map_to_arr(t_map *map, char *av);
int		map_check(t_map *map);
void	map_fix(t_map *map);
int		map_name_check(char *s);
int		map_wall_check(t_map *map);
void    map_arr_to_real(t_map *map);

fd[2];



//get_next_line
char	*ft_strchr(const char *str, int ch);
char	*ft_get_one_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_search_n_str(int fd, char *left_str);
char	*get_next_line(int fd);

//core
void	put_map(t_map *map);
int		is_str_space(char *s);





#endif