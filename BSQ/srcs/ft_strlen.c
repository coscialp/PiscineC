/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: oslussot <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 17:33:34 by oslussot     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 13:52:57 by oslussot    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *str)
{
	int		cmpt;

	cmpt = 0;
	while (str[cmpt] != '\0')
	{
		cmpt++;
	}
	return (cmpt);
}
