/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_int_tab.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 10:47:51 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 15:25:18 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

void	ft_display_int_tab(int **board, t_setup setup)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < setup.height)
	{
		j = 0;
		while (j < setup.length)
		{
			ft_putchar(board[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
