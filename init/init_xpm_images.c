#include "../game_header_here.h"

bool	init_xpm_images(t_game *game)
{
	game->xpm_images[xpm_home_screen] = set_new_xpm("assets/home_screen.xpm", &game->win);
	game->xpm_images[xpm_game_over] = set_new_xpm("assets/game_over.xpm", &game->win);
	game->xpm_images[xpm_menu] = set_new_xpm("assets/menu.xpm", &game->win);
	game->xpm_images[xpm_map_focus] = set_new_xpm("assets/map.xpm", &game->win);
	game->xpm_images[xpm_inventory] = set_new_xpm("assets/inventory.xpm", &game->win);
	return (true);
}
