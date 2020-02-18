/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlecaill <nlecaill@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:56:02 by dgascon           #+#    #+#             */
/*   Updated: 2020/02/18 09:49:58 by nlecaill         ###   ########lyon.fr   */
/*                                                                            */
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
# include <pthread.h>

# define OBJ_TEX 1
# define W_TEX 6
# define HUD_TEX 1

# define THREADS	8
# define NB_THREAD	((THREADS > 0 && THREADS < 401) ? THREADS : 1)

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef	struct	s_image
{
	void	*img;
	char	*add_image;
	int		bpp;
	int		size_line;
	int		endian;
	int		colors;
	t_coord	size;
}				t_image;

typedef struct	s_lsprite
{
	t_coord pos;
	t_coord grd;
	t_coord detect_position;
	float	detect_dist;
	int		visible[NB_THREAD];
	int		printed;
	float	dist;
	void	*next;
	t_image texture;
}				t_lsprite;

typedef	struct	s_data
{
	t_mlx		mlx;
	t_screen	screen;
	t_world		world;
	t_player	player;
	t_raycast	raycast;
	t_image		image;
	t_image		w_tex[6];
	t_image		hud_tex[1];
	t_image		minimap;
	t_actions	actions;
	t_image		object[OBJ_TEX];
	t_lsprite	*lst;
	int			th_num;
	int			bmp_save;
}				t_data;

int				init_texture(t_data *data, t_image *image, char *path);
int				flaginit_tex(t_data *data, int flag, t_image *img, char *path);
void			mlx_rect(t_image *image, t_coord pos, t_coord size, int colors);
void			mlx_line(t_data *data, t_coord start, t_coord end, int colors);
void			mlx_text(t_data *data, t_coord pos, char *text, int colors);
int				scan(t_data *data);
void			minimap(t_data *data);
t_lsprite		*lsprite_new(t_coord pos, t_image texture);
int				set_visible(t_lsprite *list, t_coord grid);
t_lsprite		*pick_object(t_lsprite *list, t_coord grid);
void			lsprite_addback(t_lsprite **lst, t_lsprite *new);
void			lsprite_sort(t_lsprite **lst);
void			pt_floor_ceil(t_data *data, int row, int qte_mur_sous_hdv,
					int height_proj_plane, int h_max);
char			get_index_byte(void *adresse, int nb_byte, int index);
void			*get_index_adresse(void *adresse, int nb_byte, int index);
int				save_bmp(t_data *data);

#endif
