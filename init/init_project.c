#include "../game_header_here.h"

bool	init_project(t_game **game)
{
	if (!init_game_struct(game))
		return (printf("Error: init_game_struct\n"), false);
	printf("Project initialized\n");
	return (true);
}
