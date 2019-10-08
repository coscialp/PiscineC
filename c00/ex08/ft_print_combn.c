/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_combn.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 08:47:26 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 08:33:40 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

const int MAX = 9;

int		ft_printable(int tab[MAX], int n)
{
	int i;

	i = 0;
	while (tab[i] < tab[i + 1])
		i++;
	if (i == (n - 1))
		return (1);
	else
		return (0);
}

void	ft_print(int tab[MAX], int n)
{
	int i;
	char c;

	i = 0;
	while (i < n)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (tab[0] != (10 - n))
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_while(int tab[MAX], int n, int i)
{
	tab[i]++;
	if (tab[i] == 10)
	{
		tab[i] = tab[i - 1];
		tab[i - 1]++;
	}
	if (tab[i - 1] == 10)
	{
		tab[i - 1] = tab[i - 2];
		tab[i - 2]++;
	}
}

void	ft_init_tab(int tab[MAX], int n)
{
	if (n <= 9)
	{
		if (n >= 1)
			tab[0] = 0;
		if (n >= 2)
			tab[1] = 1;
		if (n >= 3)
			tab[2] = 2;
		if (n >= 4)
			tab[3] = 3;
		if (n >= 5)
			tab[4] = 4;
		if (n >= 6)
			tab[5] = 5;
		if (n >= 7)
			tab[6] = 6;
		if (n >= 8)
			tab[7] = 7;
		if (n == 9)
			tab[8] = 8;
	}
}

void	ft_print_combn(int n)
{
	int tab[MAX];
	int i;

	i = (n - 1);
	ft_init_tab(tab, n);
	while (tab[0] != (10 - n))
	{
		if (ft_printable(tab, n) == 1)
			ft_print(tab, n);
		ft_while(tab, n, i);
	}
}
