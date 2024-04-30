#include "PQueue.h"
#include <stdio.h>

void showNext10Jobs(PQueue qu) {
    printf("\nDanh sach cac cong viec se duoc xu ly tiep theo:\n");
    int count = 0;
    PQueueNode* currentJob = qu.Head;
    while (currentJob != NULL && count < 10) {
        const char* illnessStatus = (strcmp(currentJob->Info.Ill, "Y") == 0 || strcmp(currentJob->Info.Ill, "y") == 0) ? "Co" : "Khong";
        const char* jobDescription = getJobDescription(currentJob->Info.CV);
        printf("------------------------------------------------------------------------\n");
        printf("STT: %d\n", count + 1);
        printf("Ma so sinh vien: %s\n", currentJob->Info.Mssv);
        printf("Ten sinh vien: %s\n", currentJob->Info.TenSV);
        printf("Lop: %s\n", currentJob->Info.Lop);
        printf("Tinh trang suc khoe: %s\n", illnessStatus);
        printf("Cong viec: %s\n", jobDescription);
        printf("Thoi gian: %d ngay\n", currentJob->Info.Tgian);
        printf("------------------------------------------------------------------------\n");
        currentJob = currentJob->Next;
        count++;
    }
}