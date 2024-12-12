#include "../game_header_here.h"

int	expose_hook(t_game *game)
{
	printf("expose_hook\n");
	layout_home_screen(game);
	return (0);
}
