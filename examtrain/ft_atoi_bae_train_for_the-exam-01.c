/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_bae_train_for_the-exam-01.c              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 15:44:16 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 16:02:45 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_is_base(char *base)
{
	int i;
	int j;
	int k;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		i++;
	}
	j = 0;
	while (base[j] != '\0')
	{
		k = j + 1;
		while (base[i] != '\0')
		{
			if (base[j] == base[k])
				return (0);
			k++;
		}
		j++;
	}
	return (i);
}

int		ft_nbr_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0' && c != base[i])
		i++;
	if (base[i] == '\0')
		return (-1);
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		nb;
	int		min;
	int		ibase;
	int		ubase;

	i = 0;
	min = 0;
	nb = 0;
	if (ibase = ft_is_base(base <= 1))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min++;
		i++;
	}
	while ((ubase = ft_nbr_in_base(str[i], base)) != -1)
	{
		nb *= ibase;
		nb += ubase;
		i++;
	}
	return (min % 2 ? -nb : nb);
}
