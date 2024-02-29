#include "binary_trees.h"

/**
 * binary_tree_height_p - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or -1 if @tree is NULL.
 */

int binary_tree_height_p(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_height_p(tree->left);
	right_height = binary_tree_height_p(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height_p(tree->left);
	right_height = binary_tree_height_p(tree->right);

	if (left_height != right_height)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
}
