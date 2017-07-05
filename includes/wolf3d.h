/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 07:00:43 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/06 01:23:22 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "../graphics/includes/graphics.h"

typedef struct		s_buttons
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
}					t_buttons;

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
	void			*win;
	void			*bg;
	t_buttons		buttons;
	t_desc			desc;
}					t_menu;

typedef struct		s_wolf
{
	void			*mlx;
	t_menu			menu;
}					t_wolf;

int					init(t_wolf *e);
void				menu(t_wolf *e);

#endif
