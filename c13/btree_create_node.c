/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_create_node.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/03/05 17:54:42 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/06 01:22:07 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

void		btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

void		btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	applyf(root->item);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

void		btree_apply_sufix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
	applyf(root->item);
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*current;

	if (!root || !*root || !item)
	{
		if (item && root)
			*root = btree_create_node(item);
		return ;
	}
	current = *root;
	if (cmpf(item, current->item) < 0)
	{
		if (current->left)
			btree_insert_data(&current->left, item, cmpf);
		else
			current->left = btree_create_node(item);
	}
	else
	{
		if (current->right)
			btree_insert_data(&current->right, item, cmpf);
		else
			current->right = btree_create_node(item);
	}
}

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*out;

	out = NULL;
	if (root)
	{
		out = btree_search_item(root->left, data_ref, cmpf);
		if (!out && !((*cmpf)(root->item, data_ref)))
			out = root->item;
		if (!out)
			out = btree_search_item(root->right, data_ref, cmpf);
	}
	return (out);
}

int	max(int a, int b)
{
	return (a > b ? a : b);
}

int		btree_level_count(t_btree *root)
{
	if (root)
		return (1 + max(btree_level_count(root->left), btree_level_count(root->right)));
	return (0);
}


int	g_level = 0;

static void	btree_apply_to_level(
			t_btree *root,
			int current_level,
			int *levels,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	is_first_elem;

	is_first_elem = 1;
	if (levels[current_level] == 1)
		is_first_elem = 0;
	else
		levels[current_level] = 1;
	if (current_level == g_level)
	{
		(*applyf)(root->item, current_level, is_first_elem);
		return ;
	}
	if (root->left)
		btree_apply_to_level(root->left, current_level + 1, levels, applyf);
	if (root->right)
		btree_apply_to_level(root->right, current_level + 1, levels, applyf);
}

void		btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		height;
	int		*levels;

	height = btree_level_count(root);
	if (!(levels = (int*)calloc(sizeof(int), height)))
		return ;
	while (g_level < height)
	{
		btree_apply_to_level(root, 0, levels, applyf);
		g_level++;
	}
	free(levels);
}

#include <string.h>

void	display_plus(void *item, int current_level, int is_first_elem)
{
	// if (current_level && is_first_elem)
	// 	printf("\n|\n|\n");
	// else if (current_level)
	// 	printf(" ----- ");
	printf("[%d] (%d) %s\n", current_level, is_first_elem, item);
}

void	print(void *item)
{
	printf("item:\t%s\n\n", (char *)item);
}

int		compare(void *s1, void *s2)
{
	return (strcmp((const char *)s1, (const char *)s2));
}

int		main()
{
	char *item = "test";
	t_btree	*btree;
	t_btree *tmp;

	btree = btree_create_node(item);
	btree_insert_data(&btree, "lol", compare);
	btree_insert_data(&btree, "a", compare);
	btree_insert_data(&btree, "b", compare);
	btree_insert_data(&btree, "test", compare);
	btree_insert_data(&btree, "zlan", compare);
	btree_insert_data(&btree, "zlan", compare);
	btree_insert_data(&btree, "zlan", compare);
	btree_insert_data(&btree, "zlan", compare);
	// printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", btree->item, btree->left, btree->right, btree);
	// tmp = btree->left;
	// printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	// tmp = tmp->left;
	// printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	// tmp = tmp->right;
	// printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	// tmp = btree->right;
	// printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	// tmp = tmp->right;
	// printf("item:\t\t%s\nleft_adress:\t%p\nright_adress:\t%p\nadress:\t\t%p\n\n", tmp->item, tmp->left, tmp->right, tmp);
	// btree_apply_infix(btree, print);
	// printf("%s\n", (char *)btree_search_item(btree, "test", compare));
	// printf("%d\n", btree_level_count(btree));
	btree_apply_by_level(btree, display_plus);
	return (0);
}