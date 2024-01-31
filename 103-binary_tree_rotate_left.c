#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function to left-rotate a binary tree.
 *
 * @tree: Pointer to the root node.
 *
 * Return: Pointer to the new root node.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pvt, *t;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pvt = tree->right;
	t = pvt->left;
	pvt->left = tree;
	tree->right = t;

	if (t != NULL)
		t->parent = tree;

	t = tree->parent;
	tree->parent = pvt;
	pvt->parent = t;

	if (t != NULL)
	{
		if (t->left == tree)
			t->left = pvt;
		else
			t->right = pvt;
	}

	return (pvt);
}
