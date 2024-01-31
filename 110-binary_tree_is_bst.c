#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Function to help binary_tree_is_bst.
 *
 * @tree: Pointer to the root node.
 * @small: The value of the smallest node visited.
 * @big: The value of the largest node visited.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */

int is_bst_helper(const binary_tree_t *tree, int small, int big)
{
	if (tree != NULL)
	{
		if (tree->n < small || tree->n > big)
			return (0);
		return (is_bst_helper(tree->left, small, tree->n - 1) &&
				is_bst_helper(tree->right, tree->n + 1, big));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Function to check if a binary tree
 * is a valid binary search tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
