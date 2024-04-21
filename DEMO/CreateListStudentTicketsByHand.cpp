#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//==============================================
////Tao moi mot phieu yeu cau cua sinh vien 
//void nhapTTSinhVien(ItemType& x)
//{
//	printf("Nhap ma so sinh vien: ");
//	scanf_s("%s", &x.Mssv);
//
//	printf("Nhap ho va ten sinh vien: ");
//	getchar();
//	fflush(stdin); // Flush the input buffer
//	fgets(x.TenSV, sizeof(x.TenSV), stdin); // Read input using fgets
//
//	// Remove newline character if present
//	if (x.TenSV[strlen(x.TenSV) - 1] == '\n')
//		x.TenSV[strlen(x.TenSV) - 1] = '\0';
//
//	printf("Nhap lop cua sinh vien: ");
//	fflush(stdin); // Flush the input buffer
//	fgets(x.Lop, sizeof(x.Lop), stdin); // Read input using fgets
//
//	// Remove newline character if present
//	if (x.Lop[strlen(x.Lop) - 1] == '\n')
//		x.Lop[strlen(x.Lop) - 1] = '\0';
//
//	printf("Co the co benh khong (Y/N): ");
//	getchar();
//	fflush(stdin); // Flush the input buffer
//	fgets(x.Ill, sizeof(x.Ill), stdin); // Read input using fgets
//
//	// Remove newline character if present
//	if (x.Ill[strlen(x.Ill) - 1] == '\n')
//		x.Ill[strlen(x.Ill) - 1] = '\0';
//
//	printf("Chon cong viec muon xu li: ");
//	scanf_s("%d", &x.CV);
//
//	printf("Nhap thoi gian dien phieu: ");
//	scanf_s("%d", &x.Tgian);
//}
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
		if (insert(PQU, p) == 0) continue;
	}
}
