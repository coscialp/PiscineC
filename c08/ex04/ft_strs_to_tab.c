/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strs_to_tab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 23:26:12 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 00:24:47 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int				i;
	int				j;
	char			*dest;

	dest = NULL;
	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	j = 0;
	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int					ft_strlen_tab(int size, char **strs)
{
	int				i;
	int				j;
	int				strlen;

	i = 0;
	strlen = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
			strlen++;
		}
		i++;
	}
	return (strlen);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*tab;

	i = 0;
	if (!((tab = malloc(sizeof(t_stock_str) * ac + 1))))
	{
		tab = NULL;
		return (tab);
	}
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].copy = malloc(sizeof(char) * ft_strlen(av[i]));
		tab[i].str = av[i];
		tab[i].copy = malloc(sizeof(char) * ft_strlen(ft_strdup(av[i])));
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
