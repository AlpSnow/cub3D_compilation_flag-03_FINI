#include "../../cub3d.h"






static mlx_image_t *determine_wall_texture(const t_resources *resources, const t_raycast_data *ray)
{
    if (ray->hit_side != 0)
    {
        if (ray->ray_direction_y < 0)
            return (resources->north_image);
        else
            return (resources->south_image);
    }
    else
    {
        if (ray->ray_direction_x < 0)
            return (resources->west_image);
        else
            return (resources->east_image);
    }
}



mlx_image_t *determine_texture_and_hit_column(const t_resources *resources, const t_raycast_data *ray, int *wall_hit_x)
{

    mlx_image_t *texture;
    double wall;

    texture = determine_wall_texture(resources, ray);               



    if (ray->hit_side)
        wall = resources->player_data.position_x + ray->perp_distance * ray->ray_direction_x;
    else
        wall = resources->player_data.position_y + ray->perp_distance * ray->ray_direction_y;

    wall = wall - floor(wall);

    *wall_hit_x = (int)(wall * texture->width);

    if ((ray->hit_side == 0 && ray->ray_direction_x > 0) || (ray->hit_side == 1 && ray->ray_direction_y < 0))
        *wall_hit_x = texture->width - *wall_hit_x - 1;


    return (texture);
}



