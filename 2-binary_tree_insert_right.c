#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as the right child
 * of a parent node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = NULL;

	if (parent == NULL)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
	{
		return (NULL);
	}

	newnode->n = value;
	newnode->left = NULL;
	newnode->right = NULL;

	newnode->parent = parent;
	if (parent->right != NULL)
	{
		parent->right->parent = newnode;
		newnode->right = parent->right;
		parent->right = newnode;
	}
	else
	{
		parent->right = newnode;
	}

	return (newnode);
}
