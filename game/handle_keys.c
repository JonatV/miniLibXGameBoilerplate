#include "../game_header_here.h"

void	handle_keys(t_game *game)
{
	if (game->keys.esc)
		close_game(game);
}
