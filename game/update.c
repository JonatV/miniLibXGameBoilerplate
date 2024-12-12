#include "../game_header_here.h"

/* Behave as a game loop
** It updates regarding the fps set in the game struct
*/
int	update(t_game *game)
{
	bool	toogle = false;

	// handle fps
	if (timestamp_in_ms(game) - game->updated_at >= (uint64_t)(1000 / game->fps))
	{
		game->updated_at = timestamp_in_ms(game);
		toogle = !toogle;
		if (toogle)
			printf("\e[1;31mFPS: %d\e[0m\n", game->fps);
		else
			printf("FPS: %d\n", game->fps);
		// code to update the game here
		handle_keys(game);
	}
	return (0);
}
