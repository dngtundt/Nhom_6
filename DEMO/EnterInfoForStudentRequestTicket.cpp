#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Tao moi mot phieu yeu cau cua sinh vien 
void enterInfoForStudentRequestTicket(ItemType& x)
{
	printf("Nhap ma so sinh vien: ");
	getchar();
	fflush(stdout); // Ensure the prompt is displayed before input
	fgets(x.Mssv, sizeof(x.Mssv), stdin); // Read input using fgets
	// Remove newline character if present
	if (x.Mssv[strlen(x.Mssv) - 1] == '\n')
		x.Mssv[strlen(x.Mssv) - 1] = '\0';

	printf("Nhap ho va ten sinh vien: ");
	fgets(x.TenSV, sizeof(x.TenSV), stdin); // Read input using fgets

	// Remove newline character if present
	size_t len = strlen(x.TenSV);
	if (len > 0 && x.TenSV[len - 1] == '\n') {
		x.TenSV[len - 1] = '\0'; // Remove newline character
		printf("Nhap lop cua sinh vien: ");
		fflush(stdin); // Flush the input buffer
		fgets(x.Lop, sizeof(x.Lop), stdin); // Read input using fgets

		// Remove newline character if present
		if (x.Lop[strlen(x.Lop) - 1] == '\n')
			x.Lop[strlen(x.Lop) - 1] = '\0';
		char SoKhoa[3];
		strncpy(SoKhoa, x.Lop, 2);
		SoKhoa[2] = '\0';
		x.SoKhoa = atoi(SoKhoa);
		x.IsCntt = (strstr(x.Lop, "DHTH") != NULL ||
			strstr(x.Lop, "DHBM") != NULL ||
			strstr(x.Lop, "DHKHDL") != NULL);
		printf("Sinh vien nay co benh hay khong? (Y/N): ");
		fflush(stdin);
		fgets(x.Ill, sizeof(x.Ill), stdin);
		if (x.Ill[strlen(x.Ill) - 1] == '\n')
			x.Ill[strlen(x.Ill) - 1] = '\0';
		x.IsGoodHeal = (x.Ill[0] == 'N' || x.Ill[0] == 'n');
		showRequestTypes();
		printf("\nChon cong viec muon xu li: ");
		scanf_s("%d", &x.CV);

		printf("Nhap thoi gian dien phieu: ");
		scanf_s("%d", &x.Tgian);
	}
}