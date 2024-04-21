#include"PQueue.h"

void createPQueue(PQueue& PQU) {
	//Tao hang doi nhap tu ban phim
	int n;
	do
	{
		printf("Nhap so luong sinh vien: ");
		scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		printf("\nThong tin sinh vien thu %d: \n", i + 1);
		ItemType x;
		enterInfoForStudentRequestTicket(x);
		PQueueNode* p = createPQueueNode(x);
		p->priority = calculatePriority(&x);
		if (insert(PQU, p) == 0) continue;
	}
}
