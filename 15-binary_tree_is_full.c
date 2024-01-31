#include "binary_trees.h"

/**
 * is_full_recursive - Function to check if a binary tree
 * is full recursively or not.
 *
 * @tree: Pointer to the root node.
 *
 * Return: 0 if tree is not full and 1 if it is.
 */

int recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
				(tree->left == NULL && tree->right != NULL) ||
				recursive(tree->left) == 0 ||
				recursive(tree->right) == 0)
		{
			return (0);
		}
	}

	return (1);
}

/**
 * binary_tree_is_full - Function to just check if
 * a binary tree is full.
 *
 * @tree: Pointer to the root node.
 *
 * Return: 0 if tree is NULL or is not full and 1 Otherwise.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (recursive(tree));
}
