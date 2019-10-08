/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_params.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 12:59:14 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 22:35:46 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

void	ft_sort_params(char **params, int ac)
{
	int		i;
	char	*buff;

	i = 2;
	while (i < ac)
	{
		if ((ft_strcmp(params[i - 1], params[i])) > 0)
		{
			buff = params[i - 1];
			params[i - 1] = params[i];
			params[i] = buff;
			i = 1;
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		ft_putstr(params[i]);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	ft_sort_params(av, ac);
	return (0);
}
