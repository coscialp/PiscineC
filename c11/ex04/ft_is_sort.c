/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_sort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 18:10:23 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 16:48:46 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (((*f)(tab[i], tab[i + 1]) == 0) && i < length)
		i++;
	if ((*f)(tab[i], tab[i + 1]) < 0)
	{
		while (i < length)
		{
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	if ((*f)(tab[i], tab[i + 1]) > 0)
	{
		while (i < length)
		{
			if ((*f)(tab[i], tab[i + 1]) < 0)
				return (0);
			i++;
		}
	}
	return (1);
}
