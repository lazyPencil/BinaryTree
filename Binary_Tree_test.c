#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Binary_Tree.h"

void printTree(TreeNode* pTree);

int main(void) {
	char in[10] = { 'A','B','C','D','E','F','G',0 };
	TreeNode* pTree1 = createTree(NULL, in[3], NULL);
	TreeNode* pTree2 = createTree(NULL, in[4], NULL);
	TreeNode* pTree3 = createTree(NULL, in[5], NULL);
	TreeNode* pTree4 = createTree(NULL, in[6], NULL);
	TreeNode* pTree5 = createTree(pTree1, in[1], pTree2);
	TreeNode* pTree6 = createTree(pTree3, in[2], pTree4);
	TreeNode* Root = createTree(pTree5, in[0], pTree6);
	TreeNode* pTemp = NULL;

	printf("Root addr = %p , Root->left = %p , Root->right = %p\n", Root, Root->left, Root->right);
	
	printTree(Root);
	destroyTree(Root);
	return 0;
}
void printTree(TreeNode* pTree) { // in-order notation
	if (pTree != NULL) {
		printTree(pTree->left);
		printf("%c ", TreeData(pTree));
		printTree(pTree->right);
	}
	else
		return;
}