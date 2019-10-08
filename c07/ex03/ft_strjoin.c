/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 15:40:21 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 17:26:13 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen_strs(char **strs, int size, char *sep)
{
	int	strlen;
	int j;
	int i;

	strlen = 0;
	i = 0;
	while (i != size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			strlen++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	i = i * (size - 1);
	return (strlen + i + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		return (str);
	}
	k = 0;
	i = -1;
	if (!(str = malloc(sizeof(str) * ft_strlen_strs(strs, size, sep))))
		return (NULL);
	while (++i != size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
			str[k++] = strs[i][j];
		j = -1;
		while ((sep[++j] != '\0') && (i < size - 1))
			str[k++] = sep[j];
	}
	str[k] = '\0';
	return (str);
}
