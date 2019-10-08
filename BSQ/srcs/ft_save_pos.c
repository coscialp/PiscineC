/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_pos.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lchauvin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 16:42:16 by lchauvin     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 19:04:16 by lchauvin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

struct s_save	ft_save_pos(t_save save, int line, int col, int val)
{
	if (val > save.val)
	{
		save.line = line;
		save.col = col;
		save.val = val;
	}
	return (save);
}
