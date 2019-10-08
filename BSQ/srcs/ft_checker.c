/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_checker.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lchauvin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 18:39:40 by lchauvin     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 17:09:27 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int		ft_checker(int **tab, int line, int col)
{
	int a;
	int b;
	int c;

	if (tab[line][col] == -1)
		return (-1);
	c = tab[line][col - 1];
	b = tab[line - 1][col - 1];
	a = tab[line - 1][col];
	if (c > b)
		c = b;
	if (c > a)
		c = a;
	return (c + 1);
}
