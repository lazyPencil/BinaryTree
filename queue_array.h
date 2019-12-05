////////////////BFS 구현 시 사용되는 Queue는 TreeNode*를 데이터로 가진다.
#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "Binary_Tree.h"

typedef struct {					
	TreeNode** arr;
	int size;
	int front, rear;
}queue;

queue* createQ(int size);			
void enqueue(queue* pQ, TreeNode* item);	
TreeNode* dequeue(queue* pQ);				
TreeNode* queuefront(queue* pQ);			
TreeNode* queuerear(queue* pQ);			
bool isfullqueue(queue* pQ);		
bool isemptyqueue(queue* pQ);		
void clearqueue(queue* pQ);			
void destroyqueue(queue* pQ);		