#include "queue_array.h"

queue* createQ(int size) {
	queue* pQ = (queue*)malloc(sizeof(queue));
	int i;
	if (pQ == NULL) return NULL;
	pQ->arr = (TreeNode**)malloc(sizeof(TreeNode*) * size);
	if (pQ->arr == NULL) {
		free(pQ);
		return NULL;
	}
	for (i = 0; i < size; i++) {
		pQ->arr[i] = (TreeNode*)malloc(sizeof(TreeNode));
	}
	pQ->front = pQ->rear = 0;
	pQ->size = size;
	return pQ;
}
void enqueue(queue* pQ, TreeNode* item) {
	if (isfullqueue(pQ)) {
		printf("queue is full...\n");
		return;
	}
	else
	{
		pQ->rear = (pQ->rear + 1) % pQ->size;
		pQ->arr[pQ->rear] = item;
	}
}
TreeNode* dequeue(queue* pQ) {
	TreeNode* x;
	if (isemptyqueue(pQ)) {
		printf("queue is empty...\n");
		return NULL;
	}
	else {
		pQ->front = (pQ->front + 1) % pQ->size;
		x = pQ->arr[pQ->front];
		return x;
	}
}
TreeNode* queuefront(queue* pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->arr[pQ->front];
}
TreeNode* queuerear(queue* pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->arr[pQ->rear];
}
bool isfullqueue(queue* pQ) {
	if ((pQ->front - pQ->rear == 1) || (pQ->rear - pQ->front == pQ->size - 1)) // r,f ¼øÀÏ ¶© ÀüÀÚ / f,r ¼øÀÏ ¶© ÈÄÀÚ
		return true;
	else
		return false;
}
bool isemptyqueue(queue* pQ) {
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}
void clearqueue(queue* pQ) {
	pQ->rear = pQ->front;
}
void destroyqueue(queue* pQ) {
	int i;
	for (i = 0; i < pQ->size; i++)
		free(pQ->arr[i]);
	free(pQ->arr);
	free(pQ);
}