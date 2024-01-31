#include "binary_trees.h"

/**
 * bst_insert - Function to insert a value in a Binary Search Tree.
 *
 * @tree: Double pointer to the root node.
 * @value: Value of the node to insert.
 *
 * Return: Pointer to the created node if true and NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new_node;

	if (tree != NULL)
	{
		current = *tree;

		if (current == NULL)
		{
			new_node = binary_tree_node(current, value);
			if (new_node == NULL)
				return (NULL);

			return (*tree = new_node);
		}

		if (value < current->n)
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));

			new_node = binary_tree_node(current, value);
			if (new_node == NULL)
				return (NULL);

			return (current->left = new_node);
		}

		if (value > current->n)
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));

			new_node = binary_tree_node(current, value);
			if (new_node == NULL)
				return (NULL);

			return (current->right = new_node);
		}
	}

	return (NULL);
}
