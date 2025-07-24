#include "../../cub3d.h"





static int	is_texture_png_file(char *str)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (ext == NULL || ext == str)
		return (1);
	if (ft_strcmp(ext, ".png") == 0)
		return (0);
	return (1);
}

static void	verify_opening(const char *path, t_map_data *map_data)
{
	int	fd;

	if (path == NULL)
		write_and_exit_error(ERROR_TEXTURE_PATH_NULL, map_data);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		// write(2, ERROR_TEXTURE_NOT_ACCESSIBLE_START, ft_strlen(ERROR_TEXTURE_NOT_ACCESSIBLE_START));
		// write(2, path, ft_strlen(path));

		ft_putstr_const_fd(ERROR_TEXTURE_NOT_ACCESSIBLE_START, 2);
		ft_putstr_const_fd(path, 2);


		write_and_exit_error(ERROR_TEXTURE_NOT_ACCESSIBLE_END, map_data);
	}
	close(fd);
}





static void	verify_texture_exist(t_map_data *map_data)
{
	if (is_texture_png_file(map_data->north_texture_path) == 1
	|| is_texture_png_file(map_data->south_texture_path) == 1
	|| is_texture_png_file(map_data->west_texture_path) == 1
	|| is_texture_png_file(map_data->east_texture_path) == 1)
    {
		write_and_exit_error(ERROR_TEXTURE_NOT_PNG, map_data);
    }

	verify_opening(map_data->north_texture_path, map_data);
	verify_opening(map_data->south_texture_path, map_data);
	verify_opening(map_data->west_texture_path, map_data);
	verify_opening(map_data->east_texture_path, map_data);


}




void	ensure_config_ready(t_map_data *map_data)
{
	if (map_data->north_texture_path == NULL || map_data->south_texture_path == NULL
		|| map_data->west_texture_path == NULL || map_data->east_texture_path == NULL
		|| map_data->is_floor_already_defined == 0
		|| map_data->is_ceiling_already_defined == 0)
	{
		write_and_exit_error(ERROR_MISSING_CONFIG, map_data);
	}
	verify_texture_exist(map_data);
}
