#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = NULL;

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL || parent == NULL)
	{
		return (NULL);
	}

	newnode->n = value;
	newnode->left = NULL;
	newnode->right = NULL;

	newnode->parent = parent;
	if (parent->left != NULL)
	{
		parent->left->parent = newnode;
		newnode->left = parent->left;
		parent->left = newnode;
	}
	else
	{
		parent->left = newnode;
	}

	return (newnode);
}
