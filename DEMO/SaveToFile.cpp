#include "PQueue.h"
bool saveToFile(PQueue qu, const char* fileName) {
	FILE* file = fopen(fileName, "w");
	if (!file) {
		printf("\nKhong the mo file %s de ghi du lieu", fileName);
		return false;
	}
    PQueueNode* current = qu.Head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->Next;
    }

    fprintf(file, "%d\n", count);

    current = qu.Head;
    while (current != NULL) {
        ItemType* sv = &current->Info;
        fprintf(file, "%s#%s#%s#%s#%d#%d\n",
            sv->Mssv,
            sv->TenSV,
            sv->Lop,
            sv->Ill,
            sv->CV,
            sv->Tgian
        );

        current = current->Next;
    }

    fclose(file);

    return true;
}