#ifndef GAME_HEADER_HERE_H
#define GAME_HEADER_HERE_H

#include "minilibx_linux/mlx.h"		// for mlx functions (handle window, image, etc)
#include <X11/Xutil.h>				// for keycode Macro (XK_SPACE, XK_Escape, etc)
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdint.h>

#define TITLE "My Wonderful Title"
/*----------------  utils.c  ---------------*/
uint64_t		gettimeofday_ms(void);
uint64_t		timestamp_in_ms(t_game *game);
int		encode_rgb(int r, int g, int b);
t_img		new_img(int w, int h, t_win *window);
t_img		set_new_xpm(char *path, t_win *window);
void		put_img_to_img(t_img *dst, t_img *src, int x, int y);
void		copy_pixel_img(t_img src_img, int src_x, int src_y, t_img dst_img, int dst_x, int dst_y);
int		close_game(void *p);
#endif
