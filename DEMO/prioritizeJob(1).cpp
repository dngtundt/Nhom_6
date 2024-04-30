#include"PQueue.h"

void prioritizeJob(PQueue& qu, const char* mssv) {
    PQueueNode* curr = qu.Head;
    PQueueNode* prev = NULL;

    while (curr && strcmp(curr->Info.Mssv, mssv)) {
        prev = curr;
        curr = curr->Next;
    }

    if (!curr) {
        printf("\nKhong tim thay sinh vien co ma so sinh vien %s trong danh sach.", mssv);
        return;
    }

    if (!prev) {
        printf("\nPhieu xu ly cua sinh vien %s da o dau danh sach.", mssv);
        return;
    }

    prev->Next = curr->Next;
    curr->Next = qu.Head;
    qu.Head = curr;
}