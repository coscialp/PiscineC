/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_bits.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 13:46:57 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 14:45:19 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_bits(unsigned char octet)
{
	int div;
	int oct;

	div = 128;
	oct = octet;
	while (div != 0)
	{
		if (div <= oct)
		{
			ft_putchar('1');
			oct = oct % div;
		}
		else
			ft_putchar('0');
		div = div / 2;
	}
}
