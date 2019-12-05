#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	char data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* createTree(TreeNode* L1, char Item, TreeNode* R1);
TreeNode* leftTree(TreeNode* pTree);
TreeNode* rightTree(TreeNode* pTree);
char TreeData(TreeNode* pTree);
bool isEmptyTree(TreeNode* pTree);
void destroyTree(TreeNode* pTree);


