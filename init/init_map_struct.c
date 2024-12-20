#include "../game_header_here.h"

int temp_map[MAP_H][MAP_W] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1},
	{1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
	{1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

bool init_map_struct(t_game *game)
{
	int	y;
	int	x;

	game->map.height = MAP_H;
	game->map.width = MAP_W;
	game->map.tile_size = TILE_SIZE;

	game->map.floor_color = encode_rgb(43, 31, 26);		// brown
	game->map.wall_color = encode_rgb(255, 0, 0);		// red
	game->map.empty_color = 0xFF000000;					// transparent
	game->map.player_color = encode_rgb(255, 255, 255);	// white

	game->map.map_grid = malloc(sizeof(int *) * game->map.height);
	if (!game->map.map_grid)
		return (printf("Error: map grid\n"), false);
	y = -1;
	while (++y < game->map.height)
	{
		game->map.map_grid[y] = malloc(sizeof(int) * game->map.width);
		if (!game->map.map_grid[y])
		{
			while (--y >= 0)
				free(game->map.map_grid[y]);
			free(game->map.map_grid);
			return (printf("Error: inside map grid\n"), false);
		}
	}
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
			game->map.map_grid[y][x] = temp_map[y][x];
	}
	return (true);
}
