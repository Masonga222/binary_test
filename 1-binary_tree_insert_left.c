#include "binary_trees.h"

/**
 * binary_tree_insert_left - Function to add a node on the left
 * of another node in a binary tree.
 *
 * @parent: A pointer the parent node.
 * @value: Value of the new node.
 *
 * Return: NULL if parent is NULL or an error occurs
 * and a pointer to the new node otherwise.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
