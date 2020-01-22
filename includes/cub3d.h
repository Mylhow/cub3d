/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 18:56:02 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 14:12:49 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/includes/libft.h"
# include "../libmlx/mlx.h"
# include <math.h>
# include "screen.h"
# include "world.h"
# include "player.h"
# include "raycast.h"

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef	struct 	s_image
{
	void	*img;
	char	*add_image;
	int		bpp;
	int		size_line;
	int 	endian;
	int 	colors;
}				t_image;


typedef	struct 	s_data
{
	t_mlx		mlx;
	t_screen	screen;
	t_world		world;
	t_player	player;
	t_raycast	raycast;
	t_image		image;
}				t_data;

int scan(t_data *data);
int move_up(t_data *data);
int move_down(t_data *data);

# endif