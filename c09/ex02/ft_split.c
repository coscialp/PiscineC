/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 09:26:54 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 10:01:34 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int			char_in_string(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

char		*ft_copy(char *dest, char *src, char *charset)
{
	int i;

	i = 0;
	while (char_in_string(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int			ft_size(char *str, char *charset)
{
	int i;
	int word;

	i = 0;
	word = 1;
	while (str[i])
	{
		if (char_in_string(str[i], charset) == 0 &&
				(char_in_string(str[i + 1], charset) == 1))
			word++;
		i++;
	}
	return (word);
}

void		ft_cpy_tab(char **split, char *str, char *charset)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (char_in_string(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (char_in_string(str[i + j], charset) == 0)
				j++;
			split[k] = (char *)malloc(sizeof(char) * (j + 1));
			ft_copy(split[k], str + i, charset);
			i = i + j;
			k++;
		}
	}
	split[k] = 0;
}

char		**ft_split(char *str, char *charset)
{
	int		i;
	char	**split;

	i = ft_size(str, charset);
	if (!(split = (char **)malloc(sizeof(char *) * (i + 1))))
		return (0);
	ft_cpy_tab(split, str, charset);
	return (split);
}
