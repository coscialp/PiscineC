/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_ok.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 11:53:35 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 20:25:58 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int		ft_str_is_ok(char **str, t_setup setup)
{
	int i;

	i = 0;
	if (setup.height == 1 || setup.length == 1)
		return (0);
	while (str[i])
		i++;
	if (i != setup.height + 1)
		return (-1);
	i = 1;
	while (str[i])
	{
		if (ft_strlen(str[1]) != ft_strlen(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int		ft_map_zero(char **map)
{
	if (!map[0])
		return (-1);
	if (!map[1])
		return (-1);
	return (1);
}

int		ft_str_only_char(char **str, t_setup setup)
{
	int i;
	int j;

	if (setup.height == 1 && setup.length == 1)
	{
		if (str[1][0] == setup.obs || str[1][0] == setup.empty)
			return (0);
	}
	i = 1;
	if (setup.empty == setup.obs || setup.empty == setup.full ||
			setup.full == setup.obs)
		return (-1);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != setup.empty && str[i][j] != setup.obs)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
