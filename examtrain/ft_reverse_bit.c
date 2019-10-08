/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_reverse_bit.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 14:28:29 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 15:32:07 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_print_bits(unsigned char octet);

int		ft_reverse_bits(unsigned char octet)
{
	return (((octet >> 0) & 1) << 7 |
			((octet >> 1) & 1) << 6 |
			((octet >> 2) & 1) << 5 |
			((octet >> 3) & 1) << 4 |
			((octet >> 4) & 1) << 3 |
			((octet >> 5) & 1) << 2 |
			((octet >> 6) & 1) << 1 |
			((octet >> 7) & 1) << 0);
}

int		main()
{
	ft_print_bits(ft_reverse_bits(7));
}
