#include "binary_trees.h"

/**
 * binary_tree_balance - Function to measure the balance
 * factor of a binary tree.
 *
 * @tree: Pointer to the root node.
 *
 * Return:  0 if tree is NULL and balance factor if not.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Function to measure the height.
 *
 * @tree: Pointer to the root node.
 *
 * Return: 0 if tree is NULL else height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

		left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left > right) ? left : right);
	}

	return (0);
}
