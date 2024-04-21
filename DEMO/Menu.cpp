#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//====================================================	
// lua chon cong viec muon xu ly
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
// cach tinh nang cua chuong trinh
void showMenu() {
	printf("\n                        LUA CHON										");
	printf("\n0. Thoat");
	printf("\n1. Xem danh sach phieu giai quyet yeu cau cua sinh vien hien tai");
	printf("\n2. Tao mot danh sach cong viec tu ban phim");
	printf("\n3. Them mot phieu giai quyet yeu cau cong viec cua sinh vien");
	printf("\n4. Tao mot danh sach cong viec tu FILE");
	printf("\n5. Xoa mot  sinh vien tu hang doi uu tien");
	printf("\n6. Tim kiem  sinh vien tu hang doi uu tien bang ma so sinh vien");
	printf("\n7. Dong bo file luu tru danh sach phieu giai quyet yeu cau cua sinh vien hien tai");
}