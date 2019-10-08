/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_int_tab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 19:15:10 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 13:07:01 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int buff;

	i = 0;
	while (i < size - 1)
	{
		i++;
		if (tab[i - 1] > tab[i])
		{
			buff = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = buff;
			i = 0;
		}
	}
}

int		main(void)
{
	int	tab[] = {2, 1, 4, 5, 3};
	int size = 5;
	ft_sort_int_tab(tab, size);
	printf("%d", tab[0]);
	return (0);
}
