#include "Binary_Tree.h"

TreeNode* createTree(TreeNode* L1, char Item, TreeNode* R1) {
	TreeNode* pNew = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNew == NULL) return NULL;
	pNew->data = Item;
	pNew->left = L1;
	pNew->right = R1;
	return pNew;
}
TreeNode* leftTree(TreeNode* pTree) { // ���ʿ��� �޷������� ��ȯ�� �� ���� �ʳ�..?
	if (isEmptyTree(pTree) == true) return NULL;
	return pTree->left;
}
TreeNode* rightTree(TreeNode* pTree) {
	if (isEmptyTree(pTree) == true) return NULL;
	return pTree->right;
}
char TreeData(TreeNode* pTree) {
	if (pTree == NULL) return NULL;
	return pTree->data;
}
bool isEmptyTree(TreeNode* pTree) { // �ϴ� ��,�� ���ٰ� ������
	if (pTree->left == NULL && pTree->right == NULL)
		return true;
	else
		return false;
}
void destroyTree(TreeNode* pTree) { // ��� Ȯ��!
	if (isEmptyTree(pTree) != true) {
		destroyTree(pTree->left);
		destroyTree(pTree->right);
	}
	free(pTree);
}
