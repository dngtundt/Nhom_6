#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//==============================================
// Tìm kiếm sinh viên theo mã số sinh viên 
PQueueNode* findStudentByStudentCode(PQueue qu, const char* mssv) {
	if (!mssv) return NULL;
	if (isEmpty(qu)) { 
		printf("\n co zo");
		return NULL; }
	PQueueNode* curr = qu.Head;
	while (curr) {
		if (strcmp(curr->Info.Mssv, mssv) == 0) {
			return curr;
		}
		curr = curr->Next;
	}
	return NULL;
}