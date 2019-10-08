/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/14 21:23:34 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/14 21:34:23 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char *ft_strrev(char *str)
{
	int 	i;
	int		cpt;
	int		j;
	char	buff;
	
	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	cpt = i;
	while (j < cpt / 2)
	{
		buff = str[i];
		str[i] = str[j];
		str[j] = buff;
		j++;
		i--;
	}

	return (str);
}

int		main(void)
{
	char str[10] = "123456789";
	printf("%s", ft_strrev(str));
	return (0);
}
