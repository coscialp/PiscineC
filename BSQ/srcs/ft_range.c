/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: oslussot <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 17:37:13 by oslussot     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 12:20:20 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 0;
	if (min >= max)
	{
		return (0);
	}
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (tab == 0)
	{
		return (0);
	}
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
