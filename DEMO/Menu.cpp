#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//====================================================	
// lua chon cong viec muon xu ly
void showRequestTypes() {
	printf("\n             CHON CONG VIEC MUON XU LY                ");
	printf("\n1. Gap giao vien");
	printf("\n2. Phuc khao diem");
	printf("\n3. Yeu cau chuyen khoa");
	printf("\n4. Dang ki du thi chung chi CNTT");
	printf("\n5. Mua sach CNTT");
}
//====================================================	
// cach tinh nang cua chuong trinh
void showMenu() {
	printf("\n                        LUA CHON										");
	printf("\n0. Thoat");
	printf("\n1. Xem danh sach phieu giai quyet yeu cau cua sinh vien hien tai");
	printf("\n2. Them nhieu phieu giai quyet yeu cau cong viec cua sinh vien");
	printf("\n3. Them mot phieu giai quyet yeu cau cong viec cua sinh vien");
	printf("\n4. Them phieu giai quyet yeu cau cong viec cua sinh vien tu viec doc File");
	printf("\n5. Xoa mot phieu giai quyet yeu cau cong viec cua sinh vien");
	printf("\n6. Tim kiem phieu giai quyet yeu cau cong viec cua sinh vien bang ma so sinh vien");
	printf("\n7. Dong bo file luu tru danh sach phieu giai quyet yeu cau cua sinh vien hien tai");
}