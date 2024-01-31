#include "binary_trees.h"
/*
bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);
*/
/**
 * inorder_successor - Function to find the minimum value in a BST.
 *
 * @root: Pointer to the root node.
 *
 * Return: The minimum value.
 */

bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;

	return (root);
}

/**
 * bst_delete - Function to delete a node from a binary search tree.
 *
 * @root: Pointer to the root node.
 * @node: Pointer to the node to delete.
 *
 * Return: Pointer to the new root node after deletion.
 */

bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;


	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;

		else if (parent != NULL)
			parent->right = node->right;

		if (node->right != NULL)
			node->right->parent = parent;

		free(node);

		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;

		else if (parent != NULL)
			parent->right = node->left;

		if (node->left != NULL)
			node->left->parent = parent;

		free(node);

		return (parent == NULL ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Function to remove a node in a BST recursively.
 *
 * @root: Pointer to the root node.
 * @node: Pointer to the current node.
 * @value: The value to remove.
 *
 * Return: Pointer to the root node after deletion.
 */

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));

		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));

		return (bst_remove_recursive(root, node->right, value));
	}

	return (NULL);
}

/**
 * bst_remove - Function to remove a node in a BST.
 *
 * @root: Pointer to the root node.
 * @value: The value to remove.
 *
 * Return: A pointer to the new root node after deletion.
 *
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
