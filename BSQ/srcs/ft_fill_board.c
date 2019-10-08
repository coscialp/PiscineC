/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_board.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 13:42:51 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 20:28:07 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

struct s_save	ft_fill_one(t_save save, t_setup setup, char **board)
{
	if (board[1][0] == setup.obs)
		ft_putchar(setup.obs);
	else
		ft_putchar(setup.full);
	ft_putchar('\n');
	save.val = -2;
	return (save);
}

struct s_save	ft_fill_line(t_save save, t_setup setup, char **board)
{
	int i;

	i = 0;
	while (i < setup.length)
	{
		while (board[1][i] == setup.obs && i < setup.length)
		{
			ft_putchar(setup.obs);
			i++;
		}
		if (i < setup.length)
		{
			ft_putchar(setup.full);
			i++;
		}
		while (i < setup.length)
		{
			ft_putchar(board[1][i]);
			i++;
		}
		ft_putchar('\n');
	}
	save.val = -2;
	return (save);
}

struct s_save	ft_fill_col(t_save save, t_setup setup, char **board)
{
	int i;

	i = 1;
	while (i < setup.height)
	{
		while (board[i][0] == setup.obs && i < setup.height)
		{
			ft_putchar(setup.obs);
			ft_putchar('\n');
			i++;
		}
		if (i < setup.height)
		{
			ft_putchar(setup.full);
			ft_putchar('\n');
			i++;
		}
		while (i <= setup.height)
		{
			ft_putchar(board[i++][0]);
			ft_putchar('\n');
		}
	}
	save.val = -2;
	return (save);
}

struct s_save	ft_fill(t_save save, t_setup setup, int **tab)
{
	int col;
	int line;

	col = 1;
	line = 1;
	while (line < setup.height)
	{
		while (col < setup.length)
		{
			tab[line][col] = ft_checker(tab, line, col);
			save = ft_save_pos(save, line, col, tab[line][col]);
			col++;
		}
		line++;
		col = 1;
	}
	return (save);
}

struct s_save	ft_board(t_save save, t_setup setup, char **board, int **tab)
{
	int line;
	int col;

	line = 0;
	col = 0;
	if (setup.height == 1 && setup.length == 1)
		save = ft_fill_one(save, setup, board);
	else if (setup.height == 1)
		save = ft_fill_line(save, setup, board);
	else if (setup.length == 1)
		save = ft_fill_col(save, setup, board);
	else
	{
		save = ft_init(save, setup, board);
		save = ft_fill(save, setup, tab);
	}
	return (save);
}
