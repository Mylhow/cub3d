/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_base.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 16:02:35 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 15:45:54 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sbase(enum e_base b)
{
	char *str[4];

	str[0] = "0123456789";
	str[1] = "0123456789ABCDEF";
	str[2] = "0123456789abcdef";
	str[3] = "01234567";
	return (str[b]);
}
