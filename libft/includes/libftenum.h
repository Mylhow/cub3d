/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftenum.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 15:56:07 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 12:50:11 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTENUM_H
# define LIBFTENUM_H

enum	e_boolean
{
	TRUE = 1,
	FALSE = 0
};

enum	e_base
{
	BASE10 = 0,
	BASE16U = 1,
	BASE16l = 2,
	BASE8 = 3
};

enum	e_keycode
{
	ARROW_DOWN 	= 125,
	ARROW_UP	= 126,
	ARROW_RIGHT	= 124,
	ARROW_LEFT	= 123,
	S			= 1,
	W			= 13,
	D			= 2,
	A			= 0,
	Q			= 12,
	Z			= 6,
	ESC			= 53
};

char	*ft_sbase(enum e_base b);
#endif