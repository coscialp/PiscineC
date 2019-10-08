/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_swap_bits.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 13:55:22 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 14:27:08 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_print_bits(unsigned char octet);

int		ft_swap_bits(unsigned char octet)
{
	return ((octet >> 4) + (octet << 4));
}

int		main()
{
	ft_print_bits(ft_swap_bits('0'));
}


