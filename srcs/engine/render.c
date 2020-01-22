/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 17:58:25 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:30:13 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

//A bouger
static int	rgb_int(int red, int green, int blue)
{
	int	rgb;
	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

int	select_sprite_color(t_data *data, int height_proj_plane, int wall_row)
{
	int val;
	
	t_d_coord ratio;
	val = 0;

	if (!(data->tex.img))
	{
		if (!(data->tex.img = mlx_xpm_file_to_image(data->mlx.ptr, "images/bricks64.xpm", &data->tex.size, &data->tex.size)))
			return (printf("erreur1"));
		if (!(data->tex.add_image = mlx_get_data_addr(data->tex.img, &data->tex.bpp, &data->tex.size_line, &data->tex.endian)))
			return (printf("erreur2"));
	}
	ratio.y = ((double)data->tex.size / (double)height_proj_plane);
	ratio.x = (data->raycast.face_detect == 'V') ? ((int)(data->raycast.inter.y) % 64) : ((int)(data->raycast.inter.x) % 64);
	//printf("height = %d\tratio.y = %f\tratio.x = %d\nx = %f, y = %f\n", height_proj_plane, ratio.y, (int)ratio.x, data->raycast.inter.x, data->raycast.inter.y);
	val = *(int*)(data->tex.add_image + (data->tex.size_line * (int)(wall_row * ratio.y)) + ((int)ratio.x * sizeof(int)));
	return (val);
}

int fill_column(t_data *data)
{
	int height_proj_plane;
	int row;
	double dist_proj_plane;

	//printf("%f\n", data->raycast.dist);
	dist_proj_plane = (data->screen.size.x / 2) / tan(data->player.fov);
	height_proj_plane = floor((BLOCK_SIZE * dist_proj_plane) / data->raycast.dist); //REVIEW Optimisation
	(height_proj_plane > data->screen.size.y) ? height_proj_plane = data->screen.size.y : 0;
	row = (data->screen.size.y / 2 ) - (height_proj_plane / 2);//REVIEW Optimisation
	if (data->raycast.face_detect == 'V')
		data->image.colors = rgb_int(168, 15, 119);
	else if (data->raycast.face_detect == 'H')
		data->image.colors = rgb_int(80, 26, 62);
		int wall_row = 0;
	while (row < (data->screen.size.y / 2) + (height_proj_plane / 2)) //REVIEW Optimisation
	{
		*(int*)(data->image.add_image + (row * data->image.size_line) + (data->raycast.column * sizeof(int))) = select_sprite_color(data, height_proj_plane, wall_row); //RGB
		row++;
		wall_row++;
	}
	return (0);
}