#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void process() {
	ItemType X, Y;
	PQueueNode* P, * Q;
	PQueue PQU;
	initPQueue(PQU);
	int luachon;
	int kq;
	const char* fileName = "dsSinhVien.txt";
	ItemType x;
	PQueueNode* student;
	do
	{
		showMenu();
		printf("\nLua chon mot chuc nang: ");
		scanf_s("%d", &luachon);

		switch (luachon)
		{
		case 1:
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		case 2:
			createPQueue(PQU);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		case 3:
			insertAStudentNodeIntoPQueue(PQU);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		case 4:
			ReadStudentTicketsFromFile(PQU,fileName);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		case 5:
			printf("\n nhap mssv can xoa: ");
			char mssv[250];
			scanf("%s", &mssv);
			deleteStudentFromStudentCode(PQU, mssv);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		case 6:
			char Mssv[250];
			printf("\n Nhap ma so sinh vien can tinh kiem trong danh sach phieu giai quyet cong viec: ");
			scanf("%s", &Mssv);
			student = findStudentByStudentCode(PQU, Mssv);
				if (!student) {
					printf("\n sinh vien co ma so sinh vien %s khong co trong phieu giai quyet cong viec ", Mssv);
					return;
				}
			printf("\n Thong tin phieu uu cau cua sinh vien can tim la: \n");
			showPQueueNode(student);
			break;
		default:
			break;
		}
	} while (luachon != 0);
}