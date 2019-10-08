/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 11:05:01 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 15:35:20 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;
	int minus;

	i = 0;
	minus = min;
	if (min >= max)
		return (0);
	if (!((tab = (int *)malloc((max - min) * sizeof(int)))))
		return (0);
	while (i <= (max - min))
	{
		tab[i] = minus;
		minus++;
		i++;
	}
	return (tab);
}
