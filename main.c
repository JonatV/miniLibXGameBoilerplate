#include "game_header_here.h"

int main(void)
{
	t_game	*game;

	if (!init_project(&game))
		return (1);
	printf("Initialization successful, entering mlx_loop\n");
	return 0;
}
