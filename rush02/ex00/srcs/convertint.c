/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   int.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mooudmin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 19:54:24 by mooudmin     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 20:17:31 by mooudmin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

nclude <unistd.h>
#include <stdlib.h>

voidft_putstr(char *str);

int ft_count(int nb)
{
	int div;
	int nbr;
	int count;

	count = 0;
	div = nb / 10;
	nbr = nb;
	if (nb < 10)
		return (nb);
	while (nb > 9)
	{
		nbr = div;
		nb = nb / 10;
		count ++;
	}
	return (count);
}

int ft_div(int nb)
{
	int div;
	int nbr;

	div = nb / 10;
	nbr = nb;
	if (nb < 10)
		return (nb);
	while (nb > 9)
	{
		nbr = div;
		nb = nb / 10;
	}
	return (nb);
}

int ft_mod(int nb)
{
	int mod;
	int nbr;

	mod = nb % 10;
	nbr = nb;
	if (nb < 10)
		return (nb);
	while (nb > 9)
	{
		nbr = mod;
		nb = nb % 10;
	}
	return (nb);
}

int ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

void ft_convert20(int nb)
{
	int i;
	char ret[100000] = "";
	int mod;
	int div;

	i = 0;
	div = ft_div(nb);
	mod = ft_mod(nb);
	if (nb < 10)
		ret[i] = nb + 48;
	ft_putstr(ret);
	if (nb > 9 && nb < 20)
	{
		ret[i] = div + 48;
		i++;
		ret[i] = mod + 48;
		ft_putstr(ret);
	}
}

void ft_convert100(int nb)
{
	int i;
	char ret[100000] = "";
	int mod;
	int div;

	i = 0;
	div = ft_div(nb);
	mod = ft_mod(nb);
	if (nb > 19 && nb < 100)
	{
		ret[i] = div + 48;
		i++;
		ret[i] = '0';
		i++;
		ret[i] = ' ';
		i++;
		ret[i] = mod + 48;
		ft_putstr(ret);
		write(1, "\n", 1);
	}
}

void ft_convert1000(int nb)
{
	int i;
	char ret[100000] = "";
	int mod;
	int div;

	i = 0;
	div = ft_div(nb);
	mod = ft_mod(nb);
	if (nb > 99 && nb < 1000)
	{
		ret[i] = div + 48;
		i++;
		ret[i] = ' ';
		i++;
		ret[i] = '1';
		i++;
		ret[i] = '0';
		i++;
		ret[i] = '0';
		nb = nb - (div * 100);
		ft_putstr(ret);
		write(1, "\n", 1);
	}
}

void ft_convertplus1000(int nb)
{
	int i;
	int mod;
	int div;
	int count;
	int nb1;
	int nb2;
	int nb3;

	i = 0;
	div = ft_div(nb);
	mod = ft_mod(nb);
	count = ft_count(nb);
	nb1 = ft_recursive_power(10, count);
	nb2 = ft_recursive_power(10, (count - 1));
	nb3 = ft_recursive_power(10, (count - 2));

}


void compcount01(int nb)
{
	int i;
	char ret[1000000] = "";
	int mod;
	int div;
	int count;
	int nbr;
	int nb1;

	i = 0;
	div = ft_div(nb);
	mod = ft_mod(nb);
	count = ft_count(nb);
	nb1 = ft_recursive_power(10, count);
	if (count % 3 == 0)
		ret[i] = div + 48;
	else if (count % 3 == 1)
	{
		ret[i] = div + 48;
		nbr = nb - (div * nb1);
		div = ft_div(nbr);
		i++;
		ret[i] = div + 48;
	}
}

void compcount2(int nb)
{
	int i;
	char ret[1000000] = "";
	int mod;
	int div;
	int count;
	int nb1;
	int nb2;
	int nbr;

	i = 0;
	div = ft_div(nb);
	mod = ft_mod(nb);
	count = ft_count(nb);
	nb1 = ft_recursive_power(10, count);
	nb2 = ft_recursive_power(10, count - 1);
	if (count % 3 == 2)
	{
		ret[i] = div + 48;
		nbr = nb - (div * nb1);
		div = ft_div(nbr);
		i++;
		ret[i] = div + 48;
		nbr = nbr - (div * nb2);
		div = ft_div(nbr);
		i++;
		ret[i] = div + 48;
	}
}

int ft_recurfinal(int nb)
{
	char ret[100000] = "";
	int count;
	int nb1;
	int nb2;
	int nb3;

	count = ft_count(nb);
	nb1 = ft_recursive_power(10, count);
	nb2 = ft_recursive_power(10, (count - 1));
	nb3 = ft_recursive_power(10, (count - 2));
	if (count % 3 == 0)
		nb = nb - ( (ret[0] - 48) * nb1);
	if (count % 3 == 1)
		nb = nb - ( (ret[0] -48) * nb1) - ((ret[1] - 48) * nb2);
	if (count % 3 == 2)
		nb = nb - ( (ret[0] -48) * nb1) - ((ret[1] - 48) * nb2) -((ret[2] - 48) * nb3);
	return (nb);
}

void ft_avant(int nb)
{
	int i;
	int j;
	char ret[1000000] = "";
	int count;
	int countmod3;
	int nb4;
	int nb5;

	i = 0;
	j = 0;
	ret[i + 1] = '1';
	i = i + 2;
	count = ft_count(nb);
	countmod3 = count % 3;
	nb4 = ft_recursive_power(1000, countmod3);
	nb5 = ft_count(nb4);
	while (j < nb5)
	{
		ret[i + j] = '0';
		j++;
	}
	ft_putstr(ret);
	write(1, "\n", 1);
}
void ft_endgame(int nb)
{
	int i;
	int j;
	char ret[1000000] = "";

	i = 0;
	j = 0;
	if (nb < 20)
		ft_convert20;
	else if (nb > 19 && nb < 100)
		ft_convert100;
	else if (nb > 99 && nb < 1000)
		ft_convert1000;
	else if (nb > 1000)
	{
		compcount01(nb);
		compcount2(nb);
		ft_avant(nb);
		nb = ft_recurfinal(nb);
		return (ft_endgame(nb));
	}
}
