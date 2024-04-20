#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PQueueNode* createPQueueNode(ItemType x) {
	//Cap phat 1 node moi de luu tru gia tri x
	PQueueNode* p = new PQueueNode;
	if (p == NULL) {
		printf("Khong the cap phat node moi!");
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
void xuatTTSinhVien(ItemType x)
{
	printf("| %-5d | %-20s | %-8s | %-3s | %-3d | %-6d |\n", x.Mssv, x.TenSV, x.Lop, x.Ill, x.CV, x.Tgian);
}
//====================================================
void showPQueueNode(PQueueNode* p) {
	//Hien thi thong tin 1 node ra man hinh
	xuatTTSinhVien(p->Info);
}

//====================================================
void initPQueue(PQueue& qu) {
	//Khoi tao hang doi rong
	qu.Head = NULL;
	qu.Tail = NULL;
}

//====================================================
int isEmpty(PQueue qu) {
	//Kiem tra ds rong
	if (qu.Head == NULL) {
		return 1; //hang doi qu rong
	}
	else {
		return 0; //hang doi qu ko rong
	}
}

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

		printf("%-4d  %-15d  %-20s  %-10s  %-10s  %-30s  %d gio\n", stt++, p->Info.Mssv, p->Info.TenSV, p->Info.Lop, illnessStatus, jobDescription, p->Info.Tgian);
	}
}


//====================================================
int insert(PQueue& qu, PQueueNode* p) {
	//Them node p vao cuoi hang doi
	if (p == NULL) {
		return 0;
	}
	if (isEmpty(qu) == 1) {
		qu.Head = p;
		qu.Tail = p;
	}
	else {
		qu.Tail->Next = p;
		qu.Tail = p;
	}
	return 1; //Them thanh cong
}
void menuYeuTien() {
	printf("\n=========================================================");
	printf("\n=              CHON CONG VIEC MUON XU LY                =");
	printf("\n=========================================================");
	printf("\n= 1. Gap giao vien                                      =");
	printf("\n= 2. Phuc khao diem                                     =");
	printf("\n= 3. Yeu cau chuyen khoa                                =");
	printf("\n= 4. Dang ki du thi chung chi CNTT                      =");
	printf("\n= 5. Mua sach CNTT                                      =");
	printf("\n");
}
//====================================================	
void nhapTTSinhVien(ItemType& x)
{
	printf("Nhap ma so sinh vien: ");
	scanf_s("%d", &x.Mssv);

	printf("Nhap ho va ten sinh vien: ");
	getchar();
	fflush(stdin); // Flush the input buffer
	fgets(x.TenSV, sizeof(x.TenSV), stdin); // Read input using fgets

	// Remove newline character if present
	if (x.TenSV[strlen(x.TenSV) - 1] == '\n')
		x.TenSV[strlen(x.TenSV) - 1] = '\0';

	printf("Nhap lop cua sinh vien: ");
	fflush(stdin); // Flush the input buffer
	fgets(x.Lop, sizeof(x.Lop), stdin); // Read input using fgets

	// Remove newline character if present
	if (x.Lop[strlen(x.Lop) - 1] == '\n')
		x.Lop[strlen(x.Lop) - 1] = '\0';

	printf("Co the co benh khong (Y/N): ");
	getchar();
	fflush(stdin); // Flush the input buffer
	fgets(x.Ill, sizeof(x.Ill), stdin); // Read input using fgets

	// Remove newline character if present
	if (x.Ill[strlen(x.Ill) - 1] == '\n')
		x.Ill[strlen(x.Ill) - 1] = '\0';

	printf("Chon cong viec muon xu li: ");
	menuYeuTien();
	scanf_s("%d", &x.CV);

	printf("Nhap thoi gian dien phieu: ");
	scanf_s("%d", &x.Tgian);
}

void showMenu() {
	printf("\n=========================================================");
	printf("\n=                      LUA CHON                         =");
	printf("\n= 0. Thoat                                              =");
	printf("\n= 1. Nhap thong tin cong viec cua sinh vien             =");
	printf("\n= 2. Tao mot danh sach cong viec nhap tu ban phim       =");
	printf("\n= 3. Tao mot danh sach cong viec tu FILE                =");
	printf("\n=========================================================");

}
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
		nhapTTSinhVien(x);

		PQueueNode* p = createPQueueNode(x);
		if (insert(PQU, p) == 0) continue;
	}

}
void createPQueue_LoadTextFile(PQueue& qu, const char* fileName) {
	FILE* file;
	file = fopen(fileName, "r");
	if (file == NULL) {
		printf("Error opening file %s.\n", fileName);
		return;
	}

	int n;
	if (fscanf(file, "%d\n", &n) != 1) {
		printf("Error reading number of elements from file %s.\n", fileName);
		fclose(file);
		return;
	}

	for (int i = 0; i < n; i++) {
		ItemType x;
		char line[1024];
		if (fgets(line, sizeof(line), file) == NULL) {
			printf("Error reading line %d from file %s.\n", i + 1, fileName);
			continue;
		}

		char* token = strtok(line, "#");
		x.Mssv = atoi(token);

		token = strtok(NULL, "#");
		strncpy(x.TenSV, token, sizeof(x.TenSV) - 1);
		x.TenSV[sizeof(x.TenSV) - 1] = '\0';

		token = strtok(NULL, "#");
		strncpy(x.Lop, token, sizeof(x.Lop) - 1);
		x.Lop[sizeof(x.Lop) - 1] = '\0';

		token = strtok(NULL, "#");
		strncpy(x.Ill, token, sizeof(x.Ill) - 1);
		x.Ill[sizeof(x.Ill) - 1] = '\0';

		token = strtok(NULL, "#");
		x.CV = atoi(token);

		token = strtok(NULL, "#");
		x.Tgian = atoi(token);

		PQueueNode* p = createPQueueNode(x);
		if (p == NULL) {
			printf("Error creating node for line %d.\n", i + 1);
			continue;
		}


		if (insert(qu, p) == 0) {
			printf("Error inserting node into priority queue for line %d.\n", i + 1);
		}
	}

	fclose(file);
}

void process() {
	ItemType X, Y;
	PQueueNode* P, * Q;
	PQueue PQU;
	initPQueue(PQU);
	int luachon;
	int kq;
	const char* fileName = "dsSinhVien.txt";
	do
	{
		showMenu();
		printf("\nLua chon mot chuc nang: ");
		scanf_s("%d", &luachon);

		switch (luachon)
		{
		case 1:
			nhapTTSinhVien(X);
			P = createPQueueNode(X);
			printf("Thong tin cua sinh vien vua nhap: ");
			showPQueueNode(P);
			insert(PQU, P);
			printf("\nNoi dung hang doi la: ");
			showPQueue(PQU);
			break;
		case 2:
			createPQueue(PQU);
			printf("\nDanh sach bai hat vua nhap: ");
			showPQueue(PQU);
			break;
		case 3:
			createPQueue_LoadTextFile(PQU, fileName);
			showPQueue(PQU);
			break;
		default:
			break;
		}
	} while (luachon != 0);
}