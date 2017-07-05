/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:20:07 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/20 00:03:29 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../minilibx_macos/mlx.h"

# define WIN_W 1024
# define WIN_H 768

# define ESC 53
# define BACKSPACE 51
# define SPACE 49
# define ENTER 36
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define PLUS 69
# define MINUS 78
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

typedef struct		s_key
{
	int				bol;
	int				st[2];
	int				end[2];
	int				mpx;
	int				mpy;
	int				zoom;
	char			*img;
	void			*data;
	void			*blackscreen;
	void			*mlx;
	void			*win;
	t_color			pix;
	void			*param;
	void			*param2;
}					t_key;

typedef struct		s_linker
{
	int				i;
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				ex;
	int				ey;
	int				xd;
	int				yd;
	int				xi;
	int				yi;
}					t_lk;

void				drawline(int st[2], int end[2], t_key *k);
void				img_new(t_key *k);
void				pixel_put(t_key *k, t_lk l);
t_color				get_color(int b, int g, int r, int a);
void				print(t_key *k);

#endif
