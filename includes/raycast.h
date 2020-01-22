/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycast.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 11:52:37 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 19:29:02 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "cub3d.h"

typedef struct s_data t_data;

typedef struct  s_raycast
{
	int		column;
	double	alpha;
	double	dist;
	char	face_detect;
}               t_raycast;

double	short_dist(t_data *data);
int		fill_column(t_data *data);
double	linear_intersec_h(t_data *data);
double	linear_intersec_v(t_data *data);
#endif