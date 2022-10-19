#define  _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * Remove a friend from friends array.
 * input
 *     node: the curren node
 *     name: the name of user that has been removed
 * output
 *     return the index of the friends if exist otherwise return -1 
 */
static int searchFriend(const Node* node, const char* name);

/**
 * Remove a friend from friends array.
 * input
 *     head: the head node of the list
 *     name: the name of user that has been removed
 */
static void removeFriend(Node* head, const char* name);


Node* createNode(const char* name, Node* next) {
	size_t size = strlen(name);
	Node* node = (Node*)malloc(sizeof(Node));
	assert(node != NULL);
	node->count = 0;
	node->next = next;
	node->user = (User*)malloc(sizeof(User));
	assert(node->user != NULL);
	strncpy(node->user->name, name, size);
	node->user->name[size] = '\0';                       // Terminate the string

	return node;
}

void destroyNode(Node* head) {
	int i;
	Node* tmp = NULL;
	while (head != NULL) {
		tmp = head->next;
		for (i = 0; i < MAX_FRIENDS; i++) {
			tmp->friends[i] = NULL;
		}
		head->count = 0;
		head->next = NULL;
		free(head->user);
		free(head);
		head = tmp;
	}
}

void insertNode(Node** head, const char* name) {
	Node* node = createNode(name, NULL);
	if (*head == NULL)
		*head = node;    // If the list is empty
	else {
		Node* tmp = *head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = node;
	}
}

void removeNode(Node** head, const char* name) {
	if (*head != NULL) {
		Node* prev = NULL;    // Previous node
		Node* curr = *head;    // Current node
		while (curr != NULL) {
			if (strcmp(curr->user->name, name) == 0) {
				removeFriend(*head, name);
				if (prev == NULL) {
					*head = (*head)->next;
				}
				else {
					prev->next = curr->next;
				}
				free(curr);
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}
}

Node* searchNode(Node* head, const char* name) {
	while (head != NULL) {
		if (strcmp(head->user->name, name) == 0) {
			return head;
		}

		head = head->next;
	}

	return NULL;
}

void printNode(Node* head, char* name) {
	const Node* node = searchNode(head, name);
	if (node == NULL) {
		printf(">>> %s NOT exist!\n", name);
	}
	else {
		printSingleNode(node);
	}
}

void printAllNodes(Node* head) {
	while (head != NULL) {
		printSingleNode(head);
		head = head->next;
	}
}

void saveToFile(Node* head, const char* filename) {
	if (head == NULL) return;

	FILE* fp = fopen(filename, "w");
	Node* tmp = head;
	while (tmp != NULL) {
		fprintf(fp, "%s", tmp->user->name);
		if (tmp->next != NULL) fprintf(fp, ",");
		tmp = tmp->next;
	}
	fprintf(fp, "\n");

	// Save friendship
	int i;
	tmp = head;
	while (tmp != NULL) {
		fprintf(fp, "%s,", tmp->user->name);
		for (i = 0; i < tmp->count; i++) {
			fprintf(fp, "%s", tmp->friends[i]->user->name);
			if (i != tmp->count - 1) {
				fprintf(fp, ",");
			}
		}
		fprintf(fp, "\n");
		tmp = tmp->next;
	}

	fclose(fp);	
}

Node* loadFromFile(const char* fileName) {
	Node* head = NULL;
	char* token = NULL;
	char* stoken = NULL;
	char buffer[MAX_LINE];
	const char* delim = ",";
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) return NULL;
	// Read the first line
	fgets(buffer, MAX_LINE, fp);
	trim(buffer);
	token = strtok(buffer, delim);
	while (token != NULL) {
		insertNode(&head, token);
		token = strtok(NULL, delim);
	}

	while (fgets(buffer, MAX_LINE, fp) != NULL) {
		trim(buffer);
		token = strtok(buffer, delim);
		if (token != NULL) {
			stoken = strtok(buffer, delim);
			while (stoken != NULL) {
				addFriendByName(head, token, stoken);
				stoken = strtok(NULL, delim);
			}
		}
	}

	fclose(fp);

	return head;
}

bool addFriend(Node* node1, Node* node2) {
	int index = searchFriend(node1, node2->user->name);
	if (index != -1) return false;
	// Befriend with each other
	node1->friends[node1->count++] = node2;
	node2->friends[node2->count++] = node1;

	return true;
}

bool addFriendByName(Node* head, const char* uName1, const char* uName2) {
	Node* node1 = searchNode(head, uName1);
	Node* node2 = searchNode(head, uName2);
	if (node1 == NULL || node2 == NULL || node1 == node2) return false;

	return addFriend(node1, node2);
}

int searchFriend(const Node* node, const char* name) {
	int i;
	for (i = 0; i < node->count; i++) {
		if (strcmp(node->friends[i]->user->name, name) == 0)
			return i;
	}

	return -1;
}

void removeFriend(Node* head, const char* name) {
	int i;
	while (head != NULL) {
		int idx = searchFriend(head, name);
		// If the friend exist
		if (idx != -1) {
			// Shift node forward
			for (i = idx; i < head->count - 1; i++) {
				head->friends[i] = head->friends[i + 1];
			}
			// Decrease the count by one
			head->count -= 1;
		}

		head = head->next;
	}
}

void printSingleNode(const Node* node) {
	printf("[[ Name: %s ]].\n", node->user->name);
	printf("[[ Friends: ");
	if (node->count == 0) {
		printf("Empty ]].\n");
	}
	else {
		int i;
		for (i = 0; i < node->count; i++) {
			printf("%s", node->friends[i]->user->name);
			if (i != node->count - 1) printf(", ");
		}
		printf(" ]].\n");
	}
	printf("\n");
}
