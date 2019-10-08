/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/04 20:56:00 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/05 12:15:42 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int maj;

	i = 0;
	maj = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (('0' > str[i] || str[i] > '9') &&
			('A' > str[i] || str[i] > 'Z') &&
			('a' > str[i] || str[i] > 'z') && maj == 0)
			maj = 1;
		else if (('a' <= str[i] && str[i] <= 'z') && maj == 1)
		{
			str[i] = str[i] - 32;
			maj = 0;
		}
		else if ('0' <= str[i] && str[i] <= '9')
			maj = 0;
		i++;
	}
	return (str);
}
