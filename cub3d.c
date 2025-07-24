/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:40:55 by mwallis           #+#    #+#             */
/*   Updated: 2025/07/06 20:28:21 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"









// static void	print_only_map_debug(const t_map_data *d)
// {
// 	int		y;
// 	int		x;
// 	char	*hdr;
// 	char	c;

// 	if (d == NULL || d->map == NULL)
// 		return ;
// 	printf("\n\033[1;33mMap Layout:\033[0m\n");
// 	hdr = ft_calloc(d->map_width + 1, 1);
// 	if (hdr == NULL)
// 		return ;
// 	x = -1;
// 	while (++x < d->map_width)
// 		hdr[x] = '0' + ((x / 10) % 10);
// 	x = -1;
// 	while (++x < d->map_width)
// 		hdr[x] = '0' + (x % 10);
// 	free(hdr);
// 	write(1, "\n", 1);
// 	write(1, "====================\n", 21);
// 	y = -1;
// 	while (++y < d->map_height)
// 	{
// 		write(1, "|", 1);
// 		x = -1;
// 		while (++x < d->map_width)
// 		{
// 			c = d->map[y][x];
// 			if (c == '\0')
// 				write(1, "*", 1);
// 			else if (c == ' ')
// 				write(1, ".", 1);
// 			else if (c == '\t')
// 				write(1, "\\t", 2);
// 			else if (c == '\r')
// 				write(1, "\\r", 2);
// 			else
// 				write(1, &c, 1);
// 		}
// 		write(1, "|\n", 2);
// 	}
// 	write(1, "====================\n", 21);
// }
// static void print_map_data(const t_map_data *data)
// {
// 	printf("\n\033[1;36m=== Map Data ===\033[0m\n");
// 	printf("\n\033[1;33mMap Dimensions:\033[0m\n");
// 	printf("  Width : %d\n", data->map_width);
// 	printf("  Height: %d\n", data->map_height);
// 	if (data->map != NULL)
// 		print_only_map_debug(data);
// 	else
// 		printf("\n\033[1;33mMap Layout:\033[0m (none loaded)\n");
// 	printf("\n\033[1;33mFloor Color:\033[0m   R:%3d G:%3d B:%3d\n",
// 		data->floor_color[0], data->floor_color[1], data->floor_color[2]);
// 	printf("\033[1;33mCeiling Color:\033[0m R:%3d G:%3d B:%3d\n",
// 		data->ceiling_color[0], data->ceiling_color[1], data->ceiling_color[2]);
// 	printf("\n\033[1;33mTextures:\033[0m\n");
// 	printf("  North:  %s\n", data->north_texture_path ? data->north_texture_path : "(null)");
// 	printf("  South:  %s\n", data->south_texture_path ? data->south_texture_path : "(null)");
// 	printf("  West:   %s\n", data->west_texture_path ? data->west_texture_path : "(null)");
// 	printf("  East:   %s\n", data->east_texture_path ? data->east_texture_path : "(null)");
// 	printf("\n\033[1;33mPlayer Info:\033[0m\n");
// 	printf("  Position: (%.2f, %.2f)\n", data->player_x_start, data->player_y_start);
// 	printf("  Direction: '%c'\n", data->player_direction ? data->player_direction : '-');
// 	printf("\n\033[1;36m======================\033[0m\n");
// }

// void print_player_data(const t_player_data *p)
// {
//     printf("=== Player Data ===\n");
//     printf("Position   : (%.2f, %.2f)\n", p->position_x, p->position_y);
//     printf("Direction  : (%.3f, %.3f)\n", p->direction_x, p->direction_y);
//     printf("Plane (FOV): (%.3f, %.3f)\n", p->plane_x, p->plane_y);
//     printf("====================\n");
// }









void	ft_putstr_const_fd(const char *str, int fd)
{
	ft_putstr_fd((char *)str, fd);
}








int	main(int argc, char *argv[])
{
	t_resources	resources;

	validate_input(argc, argv);

	sanitize_structs(&resources);

	init_simulation_parameters(&resources);

	init_map_data(argv[1], &resources.map_data);



	


	init_game_data(&resources);


	

	// On affiche une image grise dans la fenetre creer auparavant
	// elle prend la totalité de la fenetre! meme dimension!

	// creation de l'image : 
	// mlx_image_to_window(resources->mlx, resources->screen, 0, 0)

	// Puis on modifie constammant resources->screen avec mlx_loop_hook(resources.mlx, render_frame, &resources) 
	// ce qui modifie l'image a l'ecran




	init_screen(&resources);



	

	// En gros ceci est ce que j'avais utilisé pour faire les animations sur solong
    // a chaque tick de la boucle interne a la codam (a peu pret 60 fps) la MLX appelle la fonction que tu lui donne ici render_frame()
    // mlx_loop_hook(resources.mlx, render_frame, &resources);
	



	
	// version 24fps clavier
	// render_frame(&resources);
	
	// mlx_key_hook(resources.mlx, &handle_keypress, &resources);





	// version 60fps
	mlx_loop_hook(resources.mlx, &engine_loop, &resources);

// render_frame(&resources);




	// boucle classique de la mlx sinon la fenetre reste meme pas a l'ecran
	mlx_loop(resources.mlx);


	// debug
	// print_map_data(&resources.map_data);
	// print_player_data(&resources.player_data);

	// free si jamais le mec clique sur la croix.
	// ca casse juste mlx_loop donc il faut tout de meme terminate la mlx et free les images et evidemment le reste


	// write(1, INFO_WINDOW_CLOSE, ft_strlen(INFO_WINDOW_CLOSE));
	ft_putstr_const_fd(INFO_WINDOW_CLOSE, 1);


	free_game_resources(&resources);
	free_map_data(&resources.map_data);



    





	return (0);
}

