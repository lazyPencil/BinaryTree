/////////문자열을 입력받아 Complete Binary Tree로 만든 뒤 DFS(Pre,In,Pos) 와 BFS를 구현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Binary_Tree.h"
#include "queue_array.h"

void InOrder(TreeNode* pTree);
void PreOrder(TreeNode* pTree);
void PostOrder(TreeNode* pTree);
TreeNode* string2CBT(TreeNode* pRoot, char* string, int i, int n); // CBT : Complete Binary Tree
void BreadthFirstSearch(TreeNode* pRoot, queue* pQ);  // Recursion Model

int main(void) {
	int menu, error;
	char in[50] = { 0, };
	TreeNode* pRoot = NULL;
	queue* pQ = createQ(30);

	while (1) {
		printf("문자열을 입력하세요.\n");
		error = scanf("%s", &in);
		if (error != 1) continue;
		pRoot = string2CBT(pRoot, in, 0, strlen(in));
		printf("PreOrder(0),InOrder(1),PostOrder(2),Breath-First traversal(3),Exit(4)\n");
		error = scanf("%d", &menu);
		if (error != 1) {
			while (getchar() != '\n');
			continue;
		}
		getchar();
		if (menu == 4) break;
		switch (menu) {
		case 0:
			PreOrder(pRoot);
			puts("");
			break;
		case 1:
			InOrder(pRoot);
			puts("");
			break;
		case 2:
			PostOrder(pRoot);
			puts("");
			break;
		case 3:
			BreadthFirstSearch(pRoot,pQ);
			puts("");
			break;
		}
	}
	destroyqueue(pQ);
	destroyTree(pRoot);
	return 0;
}
TreeNode* string2CBT(TreeNode* pRoot, char* string, int i, int n) { // Recursion Model
	// base case : string[i]가 존재X (ex: string = ABCD\0 , n = 4 , i = 4면 string[4] = \0 이다.
	if (i >= n)
		return pRoot;
	// general case : string[i]가 존재하므로 pRoot item에 넣으면 된다.
	pRoot = createTree(NULL, string[i], NULL);
	pRoot->left = string2CBT(pRoot->left, string, 2 * i + 1, n);
	pRoot->right = string2CBT(pRoot->right, string, 2 * i + 2, n);
	return pRoot;
}
void InOrder(TreeNode * pTree) { // in-order notation
	if (pTree != NULL) {
		InOrder(pTree->left);
		printf("%c ", TreeData(pTree));
		InOrder(pTree->right);
	}
	else
		return;
}
void PreOrder(TreeNode * pTree) {
	if (pTree == NULL)
		return;
	printf("%c ", TreeData(pTree));
	PreOrder(pTree->left);
	PreOrder(pTree->right);
}
void PostOrder(TreeNode * pTree) {
	if (pTree == NULL)
		return;
	PostOrder(pTree->left);
	PostOrder(pTree->right);
	printf("%c ", TreeData(pTree));
}
void BreadthFirstSearch(TreeNode* pRoot, queue* pQ) { // Recursion Model
	TreeNode* pTemp = NULL;
	printf("%c ", TreeData(pRoot));
	if (pRoot->left != NULL)
		enqueue(pQ, pRoot->left);
	if (pRoot->right != NULL)
		enqueue(pQ, pRoot->right);
	if (!isemptyqueue(pQ)) { // general case
		pTemp = dequeue(pQ);
		BreadthFirstSearch(pTemp, pQ);
	}
	else // base case
		return;
}