/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_map.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 16:54:57 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 20:38:36 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"
#define BUF_SIZE 1

int				**create_map(char **map, t_setup setup)
{
	int			**imap;
	int			i;

	if (!(imap = (int **)malloc(sizeof(int *) * setup.height)))
		return (0);
	i = 0;
	while (map[i + 1])
	{
		if ((!(imap[i] = (int *)malloc(sizeof(int) * (ft_strlen(map[i + 1]))))))
			return (0);
		imap[i] = ft_str_translate(imap[i], map[i + 1]);
		i++;
	}
	return (imap);
}

struct s_setup	create_setup(char **map)
{
	int			height;
	int			i;
	int			y;
	int			nb;
	t_setup		setup;

	i = 0;
	y = 0;
	nb = 0;
	height = 0;
	setup.length = (ft_strlen(map[1]));
	while (map[0][i])
		i++;
	i--;
	setup.full = map[0][i];
	setup.obs = map[0][i - 1];
	setup.empty = map[0][i - 2];
	i -= 2;
	while (y < i && map[0][y] >= '0' && map[0][y] <= '9')
		nb = nb * 10 + map[0][y++] - '0';
	if (nb <= 0)
		ft_print_error();
	setup.height = nb;
	return (setup);
}

void			init_map(int **map, t_setup setup)
{
	int		i;
	int		j;

	i = 0;
	while (i < setup.height)
	{
		j = 0;
		while (j <= setup.length)
		{
			if (map[i][j] == setup.empty)
				map[i][j] = 0;
			else if (map[i][j] == setup.obs)
				map[i][j] = -1;
			j++;
		}
		i++;
	}
}
