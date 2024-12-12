#include "../game_header_here.h"

void	handle_keys(t_game *game)
{
	if (game->keys.esc)
		close_game(game);
		
	if (game->keys.enter)
	{
		if (game->state == home_screen)
			game->state = game_screen;
	}

	if (game->keys.tab && !game->keys.tab_pressed)
	{
		game->keys.tab_pressed = true;
		if (game->state == game_screen)
			game->state = inventory;
		else if (game->state == inventory)
			game->state = game_screen;
	}
	else if (!game->keys.tab)
		game->keys.tab_pressed = false;

	if (game->keys.space && !game->keys.space_pressed)
	{
		game->keys.space_pressed = true;
		if (game->state == game_screen)
			game->state = map_focus;
		else if (game->state == map_focus)
			game->state = game_screen;
	}
	else if (!game->keys.space)
		game->keys.space_pressed = false;

	if (game->keys.m && !game->keys.m_pressed)
	{
		game->keys.m_pressed = true;
		if (game->state == game_screen)
			game->state = menu;
		else if (game->state == menu)
			game->state = game_screen;
	}
	else if (!game->keys.m)
		game->keys.m_pressed = false;
}
