#include "../game_header_here.h"

int	layout_home_screen(t_game *game)
{
	put_img_to_img(&game->win.screen, &game->xpm_images[xpm_home_screen], 0, 0);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.screen.mlx_img, 0, 0);
	return (0);
}