#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>


typedef struct s_vec3
{
    double	x;
    double	y;
    double	z;
}	t_vec3;

typedef struct s_object
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;

} t_object;

typedef struct s_ray
{
    t_vec3    origin;
    t_vec3    dir;
}   t_ray;

t_vec3    vec_add(t_vec3 a, t_vec3 b);

#endif