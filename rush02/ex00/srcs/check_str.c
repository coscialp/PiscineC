/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_str.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 12:19:49 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 13:18:11 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"
#define BUF_SIZE 1

int		check_number(char *str)
{
	int i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
			i++;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (-1);
	return (ft_atoi(str));
}

char	*open_dict(char *str)
{
	int fd;
	int rd;
	int i;
	char *dict;
	char buf[BUF_SIZE];
	
	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	while ((rd = read(fd, buf, BUF_SIZE)))
		i++;
	if (!(dict =(char *)malloc(sizeof(char) * i + 1)))
		return (0);
	close(fd);
	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	read(fd, dict, i);
	close(fd);
	return (dict);
}

/*int		check_dict(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] != ':')
			{
			 	while (str[i][j] != ' ' && str[i][j] != ':')
			 	{
					if (!('0' <= str[i][j] && str[i][j] <= '9'))
						return (-1);
					j++;
				}
				j++;
			}
			if (str[i][j] == ':')
				j++;
			while (str[i][j] == ' ')
				j++;
			if (!(32 <= str[i][j] && str[i][j] <= 126))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}*/
