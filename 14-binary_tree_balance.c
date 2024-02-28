#include "binary_trees.h"

/**
 * binary_tree_height_l - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or -1 if @tree is NULL.
 */

int binary_tree_height_l(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_height_l(tree->left);
	right_height = binary_tree_height_l(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}

/**
 * binary_tree_balance - Computes the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if @tree is NULL.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height_l(tree->left);
	right_height = binary_tree_height_l(tree->right);

	return (left_height - right_height);
}
