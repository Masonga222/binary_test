#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function to right-rotate a binary tree.
 *
 * @tree: Pointer to the root node.
 *
 * Return: Pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pvt, *t;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pvt = tree->left;
	t = pvt->right;
	pvt->right = tree;
	tree->left = t;

	if (t != NULL)
		t->parent = tree;

	t = tree->parent;
	tree->parent = pvt;
	pvt->parent = p;

	if (t != NULL)
	{
		if (t->left == tree)
			t->left = pvt;
		else
			t->right = pvt;
	}

	return (pvt);
}
