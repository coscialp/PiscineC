/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 11:32:01 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 11:28:40 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterror(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		check_number(char *str);
int		check_dict(char **str);
char	*open_dict(char *str);
char	**ft_split(char *str, char *charset);

typedef	struct	s_dict
{
	int			nbr;
	char		*name;

}				t_dict;

#endif
