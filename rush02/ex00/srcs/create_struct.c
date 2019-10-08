/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_struct.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 11:24:25 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 11:51:16 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

char	*copy_name(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		size_dict(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

struct s_struct		*create_struct(char **split)
{
	t_struct	*dict;
	int i;
	int j;

	i = 0;
	j = 0;
	if(!(dict = malloc(sizeof(dict) * (size_dict(split) + 1))))
		return (0);
	while (src[j] == ' ' || src[j] == ':' || ('0' <= str[j] && str[j] <= '9'))
		j++;
	while (split[i])
	{
		dict[i].nbr = ft_atoi(split[i]);
		if(!(dict[i].name = malloc(sizeof(char *) * (j + 1))))
			return (0);
		dict[i].name = copy_name(dict[i].name, split[i+ j]);
		i++;
	}
	return (dict);
}
