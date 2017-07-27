/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 07:00:43 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/27 22:51:30 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "../graphics/includes/graphics.h"
# include "../SDL2-2.0.5/include/SDL.h"

# define MENU e->menu

typedef struct		s_wolf t_wolf;
typedef struct		s_bitmap t_bitmap;

typedef struct		s_but
{
	SDL_Texture		*solo1;
	SDL_Texture		*solo2;
	int				isload;
	SDL_Texture		*load1;
	SDL_Texture		*load2;
	SDL_Texture		*load3;
	SDL_Texture		*multi1;
	SDL_Texture		*multi2;
	SDL_Texture		*options1;
	SDL_Texture		*options2;
	SDL_Texture		*credits1;
	SDL_Texture		*credits2;
	SDL_Texture		*exit1;
	SDL_Texture		*exit2;
}					t_but;

typedef struct		s_desc
{
	SDL_Texture		*solo;
	SDL_Texture		*load;
	SDL_Texture		*multi;
	SDL_Texture		*options;
	SDL_Texture		*credits;
	SDL_Texture		*exit;
}					t_desc;

typedef struct		s_menu
{
	int				wtl;
	int				bol;
	int				no[4];
	int				yes[4];
	SDL_Texture		*bg;
	SDL_Texture		*sure;
	SDL_Texture		*quit1;
	SDL_Texture		*quit2;
	t_but			but;
	t_desc			desc;
}					t_menu;

typedef struct		s_solo
{
}					t_solo;

typedef struct		s_load
{
}					t_load;

typedef struct		s_multi
{
}					t_multi;

typedef struct		s_options
{
}					t_options;

typedef struct		s_credits
{
}					t_credits;

typedef struct		s_win
{
	int				h;
	int				w;
	char			*name;
}					t_win;

struct				s_bitmap
{
	int				height;
	int				width;
	int				*pixels;
	SDL_Renderer	*sdl_renderer;
	SDL_Texture		*sdl_texture;
	t_wolf			*e;
};

struct				s_wolf
{
	SDL_Window		*sdl_win;
	SDL_Surface		*sdl_surface;
	t_win			*win;
	t_bitmap		*framebuffer;

	t_menu			menu;
	t_solo			solo;
	t_load			load;
	t_multi			multi;
	t_options		options;
	t_credits		credits;
};

int					init(t_wolf *e);
void				error(char *str);

void				new_sdl_display(t_wolf *e, const char *title,
						int width, int height);
void				sdl_loop(t_wolf *e, int (*loop)(t_wolf *));
t_bitmap			*new_bitmap(t_wolf *e, int width, int height);
void				bitmap_draw_pix(t_bitmap *b, int x, int y, int color);
void				bitmap_update(t_bitmap *b);
void				clear_bitmap(t_bitmap *b);
void				draw_texture(SDL_Renderer *rend, SDL_Texture *img,
						int x, int y);

int					key_menu_hook(int key, t_wolf *e);
int					mouse_motion_hook_menu(int x, int y, t_wolf *e);
int					mouse_menu_hook(int button, int x, int y, t_wolf *e);
void				menu(t_wolf *e);
void				quit(t_wolf *e);
void				display_menu_classic(t_wolf *e);
void				display_desc(int x, int y, t_wolf *e);

void				solo(t_wolf *e);

void				load(t_wolf *e);

void				multi(t_wolf *e);

void				options(t_wolf *e);

void				credits(t_wolf *e);


#endif
