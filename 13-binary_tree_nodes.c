#include "binary_trees.h"

/**
 * binary_tree_nodes - Function to count the nodes that
 * have at least 1 child.
 *
 * @tree: Pointer to the root node.
 *
 * Return: 0 if tree is NULL and number of nodes otherwise.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t number_nodes = 0;

	if (tree)
	{
		number_nodes += (tree->left || tree->right) ? 1 : 0;
		number_nodes += binary_tree_nodes(tree->left);
		number_nodes += binary_tree_nodes(tree->right);
	}

	return (number_nodes);
}
