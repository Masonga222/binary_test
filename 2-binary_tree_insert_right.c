#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 * of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value of  the new node.
 *
 * Return: Null If parent is NULL or an error occurs -
 *         Otherwise - a pointer to the new node otherwise.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
