/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 19:45:11 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 20:40:09 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

struct s_save	ft_init(t_save save, t_setup setup, char **board)
{
	int i;

	i = 0;
	while (board[1][i] == setup.obs)
		i++;
	if (i < setup.length)
	{
		save.col = i;
		save.line = 0;
		save.val = 0;
	}
	if (save.val == -1 && board[2][0] != setup.obs)
	{
		save.col = 0;
		save.line = 1;
		save.val = 0;
	}
	return (save);
}
