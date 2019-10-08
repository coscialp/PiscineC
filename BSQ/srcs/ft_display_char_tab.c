/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_char_tab.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 10:25:37 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 16:26:15 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

void	display_char_tab(char **board, t_save save, t_setup setup)
{
	int i;
	int j;

	i = 1;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (i > (save.line - save.val) && i <= (save.line + 1) &&
					j >= (save.col - save.val) && j <= (save.col))
				ft_putchar(setup.full);
			else
				ft_putchar(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
