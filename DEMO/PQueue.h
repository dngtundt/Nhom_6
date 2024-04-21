#ifndef PQueue_h
#define PQueue_h


#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Khai bao du lieu
struct SinhVien
{
	char Mssv[250];
	char TenSV[500];
	char Lop[250];
	int  CV;
	int Tgian;
	char Ill[3];
	int SoKhoa;
	bool IsCntt;
	bool IsGoodHeal;
};

typedef SinhVien ItemType; //Khai bao kieu du lieu nguoi dung

struct PQueueNode {
	ItemType Info; //Luu thong tin cua mot node
	int priority;// tính độ ưu tiên của sinh viên
	PQueueNode* Next; // Luu con tro den ke sau (neu co)
};

struct PQueue {
	PQueueNode* Head; //Luu con tro node dau hang doi
	PQueueNode* Tail; //Luu con tro node cuoi hang doi
};

//====================================================
//Khai bao nguyen mau ham
void nhapTTSinhVien(ItemType& x);
void xuatTTSinhVien(ItemType x);
//void loadTTSinhVien(FILE* fi, ItemType& x);

PQueueNode* createPQueueNode(ItemType x); //Cap phat 1 node moi de luu tru
void showPQueueNode(PQueueNode* p); 		//Hien thi thong tin 1 node 

void initPQueue(PQueue& qu);		//Khoi tao hang doi
int isEmpty(PQueue qu);			//Kiem tra hang doi rong
void showPQueue(PQueue qu);		//Hien noi dung cua hang doi
int insert(PQueue* qu, PQueueNode* node); //Them node vao dau hang doi
void createPQueue(PQueue& qu); 	//Tao hang doi 
void populateToStudentListFromReadingFile(PQueue& qu, const char* fileName); //Tao hang doi tu file TEXT
const char* getJobDescription(int jobCode);// mô tả công việc 
PQueueNode* findStudentByStudentCode(PQueue qu, const char* mssv);// tìm kiếm phiếu yêu cầu của sinh viên trong Priority bằng mssv
void deleteStudentFromStudentCode(PQueue& qu, const char* mssv);// đọc tên hàm
void insertAStudentNodeIntoPQueue(PQueue& PQU);// them 1 phieu yeu cau cua sinh vien vao hang doi yeu tien 
void enterInfoForStudentRequestTicket(ItemType& x);// nhap thong tin cho phieu yeu cua cua sinh vien 
void ReadStudentTicketsFromFile(PQueue& qu, const char* fileName);//Tao hang doi tu file TEXT
void menuYeuTien();// hien thi cong viec can xu ly
void showMenu();				//Hien thi menu
void process();					//Xu ly cac chuc nang
#endif  PQueue_h
