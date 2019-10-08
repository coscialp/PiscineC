/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ultimate_range.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 15:09:43 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 15:46:28 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tab;
	int minus;

	i = 0;
	minus = min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(tab = malloc((max - min) * sizeof(tab))))
		return (-1);
	while (i <= (max - min))
	{
		tab[i] = minus;
		minus++;
		i++;
	}
	*range = tab;
	return (max - min);
}
