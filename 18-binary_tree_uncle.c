#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 *
 * @node: A pointer to the node whose uncle is to be found.
 *
 * Return: A pointer to the uncle node, or NULL if @node is NULL,
 * @node has no parent or grandparent, or @node has no uncle.
 */


binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *temp = NULL;

	if (node == NULL)
		return NULL;

	temp = node->parent->parent;

	if (temp == NULL)
		return (NULL);

	if (node->parent == temp->left)
		return (temp->right);

	return (temp->left);
}	
