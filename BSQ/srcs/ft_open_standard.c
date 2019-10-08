/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_open_standard.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 16:48:03 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 20:26:18 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

char			*open_standard(void)
{
	int			len;
	int			oct;
	char		*buf;
	char		*res;

	len = 0;
	oct = 1;
	res = malloc(sizeof(char));
	res[0] = '\0';
	buf = malloc(sizeof(char) * (55000 + 1));
	while (oct != 0)
	{
		oct = read(0, buf, 55000);
		buf[oct] = '\0';
		len = len + oct;
		if (oct != 0)
			res = ft_realloc(res, len, buf, oct);
	}
	res[len] = '\0';
	return (res);
}

char			*open_map(char *str)
{
	int			len;
	int			oct;
	int			fd;
	char		*buf;
	char		*res;

	len = 0;
	oct = 1;
	fd = open(str, O_RDONLY);
	res = malloc(sizeof(char));
	res[0] = '\0';
	buf = malloc(sizeof(char) * (55000 + 1));
	while (oct != 0)
	{
		oct = read(fd, buf, 55000);
		buf[oct] = '\0';
		len = len + oct;
		if (oct != 0)
			res = ft_realloc(res, len, buf, oct);
	}
	res[len] = '\0';
	close(fd);
	return (res);
}

char			*ft_realloc(char *old, int len, char *src, int oct)
{
	char		*new;

	new = malloc(sizeof(char) * (len + 1));
	ft_strcpy(new, old);
	ft_strcat(new, src, len, oct);
	free(old);
	return (new);
}
