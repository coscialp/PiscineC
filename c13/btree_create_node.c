/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:54:42 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/05 19:21:06 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

t_btree		*btree_create_node(void *item)
{
	t_btree	*node;

	if (!(node = (t_btree *)malloc(sizeof(t_btree) * 1)))
		return (NULL);
	node->item = item;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void		btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree *tmp;
	t_btree *new;
	t_btree *save;
	char	direction;
	
	if (!root)
		*root = btree_create_node(item);
	else
	{
		tmp = *root;
		new = btree_create_node(item);
		while (tmp)
		{
			save = tmp;
			if (cmpf(tmp->item, item) > 0)
			{
				tmp = tmp->left;
				direction = 'l';
			}
			else if (cmpf(tmp->item, item) <= 0)
			{
				tmp = tmp->right;
				direction = 'r';
			}
		}
		tmp = new;
		if (direction == 'l')
			save->left = tmp;
		else
			save->right = tmp;
	}
}

#include <string.h>

int		compare(void *s1, void *s2)
{
	return (strcmp((const char *)s1, (const char *)s2));
}

int		main()
{
	char *item = strdup("test");
	t_btree	*btree;
	t_btree *tmp;

	btree = btree_create_node(item);
	btree_insert_data(&btree, "lol", compare);
	btree_insert_data(&btree, "a", compare);
	btree_insert_data(&btree, "b", compare);
	btree_insert_data(&btree, "test", compare);
	btree_insert_data(&btree, "zlan", compare);
	printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", btree->item, btree->left, btree->right, btree);
	tmp = btree->left;
	printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	tmp = tmp->left;
	printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	tmp = tmp->right;
	printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	tmp = btree->right;
	printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	tmp = tmp->right;
	printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	return (0);
}