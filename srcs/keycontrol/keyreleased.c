/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keyreleased.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 05:11:12 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 05:11:28 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int    key_release(int key, t_data *data)
{
	if (key == ARROW_LEFT)
		data->key.arrow_left = FALSE;
	else if (key == ARROW_RIGHT)
		data->key.arrow_right = FALSE;
	else if (key == ARROW_UP)
		data->key.arrow_up = FALSE;
	else if (key == ARROW_DOWN)
		data->key.arrow_down = FALSE;
	else if (key == Q)
		data->key.incspeed = FALSE;
	else if (key == Z)
		data->key.decspeed = FALSE;
	else if (key == D)
		data->key.D = FALSE;
	else if (key == A)
		data->key.A = FALSE;
	else if (key == W)
		data->key.W = FALSE;
	else if (key == S)
		data->key.S = FALSE;
	return (0);
}