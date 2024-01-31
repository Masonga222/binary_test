#include "binary_trees.h"

/**
 * bst_search - Function to searche for a value in a BST.
 *
 * @tree: Pointer to the root node.
 * @value: The value to search for.
 *
 * Return: NULL if the tree is NULL or the value is not found
 * and a pointer to the node containing the value otherwise.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);

		if (tree->n > value)
			return (bst_search(tree->left, value));

		return (bst_search(tree->right, value));
	}

	return (NULL);
}
