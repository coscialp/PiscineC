/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gimme_value.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 17:34:03 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 17:37:23 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		gimme_value(char **tab, char c)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
