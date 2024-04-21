#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//==============================================
void insertAStudentNodeIntoPQueue(PQueue& PQU) {
	ItemType x;
	enterInfoForStudentRequestTicket(x);
	PQueueNode* p = createPQueueNode(x);
	p->priority = calculatePriority(&x);
	insert(PQU, p);
}