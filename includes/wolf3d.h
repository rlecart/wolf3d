/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 07:00:43 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 20:42:58 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "../graphics/includes/graphics.h"

# define MLX e->mlx
# define MENU e->menu
# define SOLO e->solo
# define LOAD e->load
# define MULTI e->multi
# define OPT e->options
# define CRED e->credits

typedef struct		s_but
{
	void			*solo1;
	void			*solo2;
	int				isload;
	void			*load1;
	void			*load2;
	void			*load3;
	void			*multi1;
	void			*multi2;
	void			*options1;
	void			*options2;
	void			*credits1;
	void			*credits2;
	void			*exit1;
	void			*exit2;
}					t_but;

typedef struct		s_desc
{
	void			*solo;
	void			*load;
	void			*multi;
	void			*options;
	void			*credits;
	void			*exit;
}					t_desc;

typedef struct		s_menu
{
	int				wtl;
	int				bol;
	int				no[4];
	int				yes[4];
	void			*win;
	void			*bg;
	void			*sure;
	void			*quit1;
	void			*quit2;
	t_but			but;
	t_desc			desc;
}					t_menu;

typedef struct		s_solo
{
	void			*win;
}					t_solo;

typedef struct		s_load
{
	void			*win;
}					t_load;

typedef struct		s_multi
{
	void			*win;
}					t_multi;

typedef struct		s_options
{
	void			*win;
}					t_options;

typedef struct		s_credits
{
	void			*win;
}					t_credits;

typedef struct		s_wolf
{
	void			*mlx;
	t_menu			menu;
	t_solo			solo;
	t_load			load;
	t_multi			multi;
	t_options		options;
	t_credits		credits;
}					t_wolf;

int					init(t_wolf *e);
void				destroy_windows(t_wolf *e);

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
