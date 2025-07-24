#include "../cub3d.h"

static int	is_cub_file(char *str)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (ext == NULL || ext == str)
		return (1);
	if (ft_strcmp(ext, ".cub") == 0)
		return (0);
	return (1);
}

void validate_input(int argc, char *argv[])
{
    if (argc != 2)
    {
        // write(2, ERROR_ARGC, ft_strlen(ERROR_ARGC));
        ft_putstr_const_fd(ERROR_ARGC, 2);


        exit(1);
    }
	if (is_cub_file(argv[1]) == 1)
    {
        // write(2, ERROR_CUB, ft_strlen(ERROR_CUB));
        ft_putstr_const_fd(ERROR_CUB, 2);

        exit(1);
    }
}




