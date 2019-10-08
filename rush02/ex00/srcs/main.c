/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 15:07:48 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 21:02:05 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int		main(int ac, char**av)
{
	char 		*str;
	char		**split;
	t_struct	dict;

	if (ac == 2)
	{
		if (check_numbers(av[1]) == -1)
		{
			ft_puterror("Error\n");
			return (0);
		}
		if (!(str = open_dict("numbers.dict")))
			return (0);
		if (!(split = ft_split(str, "\n")))
			return (0);
		free(str);
		if (!(dict = create_struct(split)))
			return (0);
		free(split);
	}
	else
	{
		ft_puterror("Error\n");
		return (-1)
	}
	return (0);
}
