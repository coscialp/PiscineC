/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/07 02:33:29 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 16:47:02 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

char  *ft_itoa(int nb)
{
	char *str;
	int		i;
	
	i = 0;
	str = (char *)malloc(sizeof(char) * 1000);
	if (nb == -2147483648)
	{
		str[i] = '-';
		i++;
		str[i] = '2';
		i++;
		nb = 147483648;
	}
	if (nb < 0)
	{
		str[i] = '-';
		i++;
		nb = -nb;
	}
	if (nb > 9)
	{
		printf("%d\n", nb);
		ft_itoa(nb / 10);
	}
	str[i++] = *(ft_itoa(nb % 10) + '0');

/*	else
	{
		str[i] = (nb + '0');
		i++;
	}*/
	str[i] = '\0';
	return (str);
}

int		main()
{
	printf("%s", ft_itoa(-2147483648));
	return (0);
}
