#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//==============================================
// Xoa 1 phieu cua sinh vien trong hang doi uu tien khi biet mssv
void deleteStudentFromStudentCode(PQueue& qu, const char* mssv) {
PQueueNode* student = findStudentByStudentCode(qu, mssv);
if (!student) {
    printf("\n Khong tim thay");
    return;
}
printf("\n Thong tin phieu uu cau cua sinh vien can xoa la: \n");
const char* illnessStatus = (strcmp(student->Info.Ill, "Y") == 0) ? "Co" : "Khong";
const char* jobDescription = getJobDescription(student->Info.CV);
printf("%-15s  %-20s  %-10s  %-10s  %-30s  %d ngay\n", student->Info.Mssv, student->Info.TenSV, student->Info.Lop, illnessStatus, jobDescription, student->Info.Tgian);
if (student == qu.Head) {
    PQueueNode* nextPNode = qu.Head->Next;
    delete(qu.Head);
    qu.Head = nextPNode;
    if (isEmpty(qu)) {
        printf("\n Ham doi uu tien rong ");
        qu.Head = qu.Tail = NULL;
    }
    return;
}
PQueueNode* prev = qu.Head;
while (prev && prev->Next != student) {
    prev = prev->Next;
}
PQueueNode* nextNode = student->Next;
delete(student);
if (nextNode)
prev->Next = nextNode;
else {
    prev->Next = NULL;
}
}
