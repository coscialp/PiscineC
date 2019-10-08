/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_base2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/15 18:40:28 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/15 18:41:15 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		is_base_ok(char *base)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		k = i + 1;
		if (base[i] == '+' || base[i] == '-' ||
				(base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		while (base[k])
		{
			if (base[i] == base[k])
				return (0);
			k++;
		}
		i++;
	}
	return (i);
}

int		is_char_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		is_everything_ok(char *str, char *base)
{
	int i;
	int lbase;

	lbase = 0;
	i = 0;
	if (!base || !str)
		return (0);
	lbase = (is_base_ok(base));
	if (lbase < 2)
		return (0);
	return (lbase);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int result;
	int lbase;
	int sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	lbase = is_everything_ok(str + i, base);
	if (!lbase)
		return (0);
	while (str[i] && (is_char_in_base(str[i], base) != -1))
	{
		result *= lbase;
		result += is_char_in_base(str[i], base);
		i++;
	}
	return (result * sign);
}
