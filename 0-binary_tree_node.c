#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node in a binary tree
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to store in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = NULL;

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = value;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = parent;

	return (newnode);
}
