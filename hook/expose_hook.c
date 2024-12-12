#include "../game_header_here.h"

int	expose_hook(t_game *game)
{
	(void)game;
	int	i;

	printf("expose_hook\n");
	put_img_to_img(&game->win.screen, &game->xpm_images[xpm_home_screen], 0, 0);
	i =	0;
	while (i < 100)
	{
		draw_vertex(&game->win.screen, 400 + i, 30 - (i/2), 700, 400, encode_rgb(255, 75, 0));
		i++;
	}
	draw_line_horizontal(&game->win.screen, 0, 400, 800, encode_rgb(255, 255, 255));
	draw_line_vertical(&game->win.screen, 400, 0, 800, encode_rgb(255, 255, 255));
	draw_circle(&game->win.screen, 400, 400, 100, encode_rgb(0, 255, 0));
	draw_rect(&game->win.screen, 200, 200, 100, 100, encode_rgb(0, 0, 255));
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.screen.mlx_img, 0, 0);
	return (0);
}
