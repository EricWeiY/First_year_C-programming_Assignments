#define _CRT_SECURE_NO_WARNINGS
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef max
#define max(a, b) a>b?a:b
#endif // !max

static AVLNode* getMinNode(AVLNode* root) {
	AVLNode* current = root;
	while (current->left != NULL)
		current = current->left;

	return current;
}


static int getHeight(const AVLNode* aNode) {
	if (aNode == NULL) return 0;

	return aNode->height;
}

static int balance(AVLNode* root) {
	if (root == NULL) return 0;
	return getHeight(root->left) - getHeight(root->right);
}

AVLNode* createAVLNode(const char* name) {
	size_t size = strlen(name);
	AVLNode* aNode = (AVLNode*)malloc(sizeof(AVLNode));
	assert(aNode != NULL);
	aNode->count = 0;
	aNode->left = NULL;
	aNode->right = NULL;
	aNode->user = (User*)malloc(sizeof(User));
	assert(aNode->user != NULL);
	strncpy(aNode->user->name, name, size);
	aNode->user->name[size] = '\0';                       // Terminate the string

	return aNode;
}

AVLNode* rightRotate(AVLNode* aNode) {
	AVLNode* left = aNode->left;		// Get the left child
	AVLNode* lright = left->right;		// Get the right child of left child
	left->right = aNode;				// Rotate
	aNode->left = lright;
	
	aNode->height = max(getHeight(aNode->left), getHeight(aNode->right)) + 1;
	left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

	return left;
}

AVLNode* leftRotate(AVLNode* aNode) {
	AVLNode* right = aNode->right;
	AVLNode* rleft = right->left;

	right->left = aNode;
	aNode->right = rleft;

	aNode->height = max(getHeight(aNode->left), getHeight(aNode->right)) + 1;
	right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

	return right;
}

AVLNode* insertAVLNode(AVLNode* root, const char* name) {
	if (root == NULL) return createAVLNode(name);
	int comp = strcmp(root->user->name, name);
	if (comp < 0) {
		root->left = insertAVLNode(root->left, name);
	}
	else if (comp > 0) {
		root->right = insertAVLNode(root->right, name);
	}
	else {
		return root;
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	// Calculate the height difference
	int diffH = getHeight(root->left) - getHeight(root->right);

	// Left Left 
	if (diffH >= 2 && strcmp(name, root->left->user->name) < 0) {
		return rightRotate(root);
	}

	// Right Right
	if (diffH <= -2 && strcmp(name, root->right->user->name) > 0) {
		return leftRotate(root);
	}

	// Left Right
	if (diffH >= 2 && strcmp(name, root->left->user->name) > 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left
	if (diffH <= -2 && strcmp(name, root->right->user->name) < 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

AVLNode* removeAVLNode(AVLNode* root, const char* name) {
	if (root == NULL) return NULL;
	int comp = strcmp(root->user->name, name);
	if (comp < 0) {
		root->right = removeAVLNode(root->right, name);
	}
	else if (comp > 0) {
		root->left = removeAVLNode(root->left, name);
	}
	else {
		// One child or no child
		if (root->left == NULL || root->right == NULL) {
			AVLNode* tmp = root->left ? root->left : root->right;
			free(root->user);
			free(root);
			root = tmp;
		}
		else {
			AVLNode* tmp = getMinNode(root->right);
			strncpy(root->user->name, tmp->user->name, strlen(tmp->user->name));
			root->right = removeAVLNode(root->right, tmp->user->name);
		}
	}

	if (root == NULL) return NULL;
	// Calculate the height difference
	int diffH = balance(root);

	// Left Left 
	if (diffH >= 2 && balance(root->left) >= 0) {
		return rightRotate(root);
	}

	// Right Right
	if (diffH <= -2 && balance(root->right) <= 0) {
		return leftRotate(root);
	}

	// Left Right
	if (diffH >= 2 && balance(root->left) > 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left
	if (diffH <= -2 && balance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}
