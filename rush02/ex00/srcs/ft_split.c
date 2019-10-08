/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 19:04:24 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 19:27:05 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int			char_in_string(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (str[i] != '\0')
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
		if (char_in_string(str[i], charset) == 1 &&
				(char_in_string(str[i + 1], charset) == 0 ||
				str[i + 1] == '\0'))
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
			if (str[i + j] == '\0')
				split[k] = (char *)malloc(sizeof(char) * j);
			else
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

	if (charset[0] == '\0')
	{
		split = malloc(sizeof(char) * 2);
		split[0] = str;
		split[1] = 0;
		return (split);
	}
	i = ft_size(str, charset);
	if (!(split = (char **)malloc(sizeof(split) * (i + 1))))
		return (0);
	ft_cpy_tab(split, str, charset);
	return (split);
}
