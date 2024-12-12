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
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;

	int		width;
	int		height;

	struct s_win	*win;
}		t_img;

typedef struct s_win
{
	char	*title;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	screen;
	int		width;
	int		height;
}		t_win;

typedef struct s_game
{
	t_win		win;
}	t_game;
/*----------------  main.c  ---------------*/
int		main(void);

/*----------------  draw_rectangle.c  ---------------*/
void		draw_rect(t_img *img, int x, int y, int w, int h, int color);

/*----------------  draw_circle.c  ---------------*/
void		draw_circle(t_img *img, int x, int y, int radius, int color);

/*----------------  draw_vertex.c  ---------------*/
int		draw_vertex(t_img *img, int x_start, int y_start, int x_end, int y_end, int color);

/*----------------  draw_line.c  ---------------*/
void		draw_line_vertical(t_img *img, int x, int y, int h, int color);
void		draw_line_horizontal(t_img *img, int x, int y, int w, int color);

/*----------------  optimization.c  ---------------*/
void		img_pix_put(t_img *img, int x, int y, int color);

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
