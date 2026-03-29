#ifndef GEOMETRY_H
# define GEOMETRY_H

#include "vector.h"




typedef struct s_plane
{
    t_vec3  point;  // A point on the plane
    t_vec3  normal; // The normal vector of the plane
}   t_plane;

typedef struct s_sphere
{
    t_vec3  center;
    double  radius;
}   t_sphere;

#endif