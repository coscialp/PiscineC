/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 15:55:53 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 19:21:29 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

void	bsq(char **map)
{
	t_setup	setup;
	t_save	save;
	int		**tab;

	save.val = -1;
	if (ft_map_zero(map) == -1)
	{
		ft_print_error();
		return ;
	}
	setup = create_setup(map);
	if (ft_str_is_ok(map, setup) == -1 || ft_str_only_char(map, setup) == -1)
	{
		ft_print_error();
		return ;
	}
	if (!(tab = create_map(map, setup)))
		return ;
	init_map(tab, setup);
	save = ft_board(save, setup, map, tab);
	if (save.val != -2)
		display_char_tab(map, ft_board(save, setup, map, tab), setup);
	free(tab);
	free(map);
}

void	pre_main_input(void)
{
	char	*str;
	char	**map;

	if (!(str = open_standard()))
		return ;
	if (!(map = ft_split(str, "\n")))
		return ;
	free(str);
	bsq(map);
}

void	pre_main_arg(char **av, int i)
{
	char	*str;
	char	**map;

	if (!(str = open_map(av[i])))
		return ;
	if (!(map = ft_split(str, "\n")))
		return ;
	free(str);
	bsq(map);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
	{
		pre_main_input();
	}
	else
	{
		while (i < ac - 1)
		{
			pre_main_arg(av, i);
			ft_putchar('\n');
			i++;
		}
		pre_main_arg(av, i);
	}
	return (0);
}
