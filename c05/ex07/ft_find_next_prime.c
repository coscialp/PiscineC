/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_find_next_prime.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 10:24:17 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 11:15:47 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int n;

	n = 3;
	if (nb == 1 || nb <= 0 || (nb % 2 == 0 && nb != 2))
		return (0);
	while (n <= nb / n)
	{
		if (nb % n == 0)
			return (0);
		n = n + 2;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
