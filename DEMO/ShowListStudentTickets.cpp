#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* getJobDescription(int jobCode) {
	switch (jobCode) {
	case 1: return "Gap giao vien";
	case 2: return "Phuc khao diem";
	case 3: return "Yeu cau chuyen khoa";
	case 4: return "Dang ki du thi chung chi CNTT";
	case 5: return "Mua sach CNTT";
	default: return "Khong xac dinh";
	}
}

//====================================================
void showPQueue(PQueue qu) {
	if (isEmpty(qu) == 1) {
		printf("Hang doi rong!");
		return;
	}

	printf("\n%-4s  %-15s  %-20s  %-10s  %-10s  %-30s  %-10s\n", "STT", "MA SO SINH VIEN", "TEN SINH VIEN", "LOP", "BENH", "CONG VIEC", "THOI GIAN");

	int stt = 1;
	for (PQueueNode* p = qu.Head; p != NULL; p = p->Next) {
		const char* illnessStatus = (strcmp(p->Info.Ill, "Y") == 0) ? "Co" : "Khong";
		const char* jobDescription = getJobDescription(p->Info.CV);

		printf("%-4d  %-15s  %-20s  %-10s  %-10s  %-30s  %d gio, priority  : %d \n", stt++, p->Info.Mssv, p->Info.TenSV, p->Info.Lop, illnessStatus, jobDescription, p->Info.Tgian,p->priority);
	}
}
