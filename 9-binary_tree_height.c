#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
	const binary_tree_t *temp = NULL;
	size_t height_A = 0, height_B = 0;

	if (tree == NULL)
		return (0);

	temp = tree; /* Store original address of tree */

	while (tree->left != NULL)
	{
		height_A++;
		tree = tree->left;
	}

	if (tree->right != NULL)
		height_A++;

	tree = temp; /* Restore original address */

	while (tree->right != NULL)
	{
		height_B++;
		tree = tree->right;
	}

	if (tree->left != NULL)
		height_B++;

	if (height_A > height_B)
		return (height_A);

	return (height_B);
}	
