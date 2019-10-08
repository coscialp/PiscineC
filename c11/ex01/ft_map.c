/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 16:54:32 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 17:02:47 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *ntab;

	i = 0;
	if (!(ntab = (int*)malloc(sizeof(int) * length)))
		return (0);
	while (i < length)
	{
		ntab[i] = (*f)(tab[i]);
		i++;
	}
	return (0);
}
