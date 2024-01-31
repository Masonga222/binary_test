#include "binary_trees.h"

/**
 * create_node - Function to create a new level order queue node.
 *
 * @node: Pinter to the new node.
 *
 * Return: NULL if an error occurs and a pointer
 * to the new node otherwise.
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Function to free a levelorder queue.
 *
 * @head: A pointer to the head of the queue.
 *
 * Return: Nothing.
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Function to push a node to the back of a levelorder queue.
 *
 * @node: Pointer to the binary tree.
 * @head: Double pointer to the head of the queue.
 * @tail: Double pointer to the tail of the queue.
 *
 * Return: Nothing.
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node;

	new_node = create_node(node);
	if (new_node == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * pop - Function to remove the head of a levelorder queue.
 *
 * @head: Double pointer to the head of the queue.
 *
 * Return: Nothing.
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Function to check if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 *
 * Return: 0 if the tree is NULL or not complete
 * and 1 otherwise.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;

		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);

				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;

		pop(&head);
	}

	return (1);
}
