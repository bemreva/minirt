#include "vector.h"
#include <math.h>
#include "geometry.h"

t_vec3    vec_add(t_vec3 a, t_vec3 b)
{
    return ((t_vec3){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vec3    vec_sub(t_vec3 a, t_vec3 b)
{
    return ((t_vec3){a.x - b.x, a.y - b.y, a.z - b.z});
}

double    vec_dot(t_vec3 a, t_vec3 b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3    ray_at(t_ray ray, double t)
{
    return (vec_add(ray.p0, (t_vec3){ray.dir.x * t, ray.dir.y * t, ray.dir.z * t}));
}

