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
	int  Mssv;
	char TenSV[22];
	char Lop[10];
	int  CV;
	int Tgian;
	char Ill[3];
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
int insert(PQueue& qu, PQueueNode* p); //Them node vao dau hang doi
void createPQueue(PQueue& qu); 	//Tao hang doi 
//void createPQueue_LoadTextFile(PQueue& qu, char FileName[]); //Tao hang doi tu file TEXT
void showMenu();				//Hien thi menu
void process();					//Xu ly cac chuc nang
#endif  PQueue_h
