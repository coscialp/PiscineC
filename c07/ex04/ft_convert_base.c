/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_base.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/15 14:40:31 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 15:55:55 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		is_base_ok(char *base);
int		ft_atoi_base(char *str, char *base);

void	ft_putnbr_base(int nbr, char *base, char *cnb, int m)
{
	int		lbase;
	int		i;
	long	nb;

	i = m;
	lbase = 0;
	nb = nbr;
	while (base[lbase])
		lbase++;
	if (nb < 0)
	{
		cnb[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		cnb[i] = base[nb % lbase];
		nb = nb / lbase;
		i--;
	}
}

int		lmalloc(int nb, int lbase)
{
	int m;

	m = 0;
	while (nb / lbase != 0)
	{
		nb /= lbase;
		m++;
	}
	if (nb <= 0)
		m++;
	return (m);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		m;
	int		nb;
	int		lbase;
	char	*cnb;

	nb = 0;
	m = 0;
	lbase = 0;
	while (base_to[lbase])
		lbase++;
	if (!is_base_ok(base_from) || !is_base_ok(base_to))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	m = lmalloc(nb, lbase);
	if (!(cnb = (char *)malloc(sizeof(char) * m + 1)))
		return (0);
	if (nb == 0)
		cnb[0] = base_to[0];
	else
		ft_putnbr_base(nb, base_to, cnb, m);
	cnb[m + 1] = '\0';
	return (cnb);
}
