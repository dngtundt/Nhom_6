#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <string>


void findClassWithMostJobs(PQueue qu) {
    // Khoi tao mot bang hash de dem so luong viec cua moi lop
    std::unordered_map<std::string, int> classCount;

    // Dem so luong viec cua moi lop
    for (PQueueNode* p = qu.Head; p != NULL; p = p->Next) {
        classCount[p->Info.Lop]++;
    }

    // Tim lop co so luong viec nhieu nhat
    int maxCount = 0;
    std::string mostJobsClass;
    for (const auto& pair : classCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostJobsClass = pair.first;
        }
    }

    // Hiển thị kết quả
    printf("\nLop co nhieu viec can xu li nhat la : %s, voi %d viec.\n\n", mostJobsClass.c_str(), maxCount);
}

