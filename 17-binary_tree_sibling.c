#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 *
 * @node: A pointer to the node whose sibling is to be found.
 *
 * Return: A pointer to the sibling node, or NULL if @node is NULL,
 * @node has no parent, or @node has no sibling.
 */


binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *temp = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	temp = node->parent;

	if (temp->right == NULL || temp->left == NULL)
		return (NULL);

	if (node == temp->left)
		return (temp->right);

	return (temp->left);

}
