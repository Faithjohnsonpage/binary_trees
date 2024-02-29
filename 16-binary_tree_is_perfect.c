#include "binary_trees.h"

/**
 * check_depth_left_most - Calculates the depth of the leftmost leaf node.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The depth of the leftmost leaf node.
 */

int check_depth_left_most(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree->left != NULL)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * is_leaf_at_depth - Checks if all leaf nodes are at a specific depth.
 *
 * @tree: A pointer to the root node of the tree.
 * @depth: The depth to check for leaf nodes.
 *
 * Return: 1 if all leaf nodes are at the specified depth, 0 otherwise.
 */

int is_leaf_at_depth(const binary_tree_t *tree, int depth)
{

	if (tree->left == NULL && tree->right == NULL)
		return (depth == 0);

	return (is_leaf_at_depth(tree->left, depth - 1) &&
		is_leaf_at_depth(tree->right, depth - 1));
}

/**
 * is_all_internal_nodes_non_empty - Checks if all internal nodes
 * have both children non-empty.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if all internal nodes have both children non-empty, 0 otherwise.
 */

int is_all_internal_nodes_non_empty(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (is_all_internal_nodes_non_empty(tree->left) &&
			is_all_internal_nodes_non_empty(tree->right));
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
	int depth = 0, leaves = 0, internal_nodes = 0;

	if (tree == NULL)
		return (0);

	depth = check_depth_left_most(tree);

	leaves = is_leaf_at_depth(tree, depth);
	if (leaves == 0)
		return (0);

	internal_nodes = is_all_internal_nodes_non_empty(tree);
	if (internal_nodes == 0)
		return (0);

	return (1);
}

