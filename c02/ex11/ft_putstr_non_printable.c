/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_non_printable.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 10:00:48 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 11:24:24 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	int				x;
	char			*base;
	unsigned char	*u_str;

	i = 0;
	base = "0123456789abcdef";
	u_str = (unsigned char *)str;
	while (u_str[i] != '\0')
	{
		if (u_str[i] < 32 || u_str[i] >= 127)
		{
			ft_putchar('\\');
			x = u_str[i] / 16;
			ft_putchar(base[x]);
			x = u_str[i] % 16;
			ft_putchar(base[x]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
