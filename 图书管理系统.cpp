#include<stdio.h>
#include "Library_System.h"
library_system library;
//1.д����---->�˵�---->ģ��
void makeMenu() {
	printf("-----------------------------------\n");
	printf("         ͼ�����ϵͳ\n");
	printf("\t0.�˳�ϵͳ\n");
	printf("\t1.�Ǽ��鼮\n");
	printf("\t2.ɾ���鼮\n");
	printf("\t3.����鼮\n");
	printf("\t4.�����鼮\n");
	printf("\t5.�����鼮\n");
	printf("\t6.�黹�鼮\n");
	printf("\t7.�鼮����\n");
	printf("-----------------------------------\n");
	printf("������(0~7):");
}


void keyDown() {
	int choice;
	scanf("%d", &choice);
	switch (choice) {
	case 0:
		library.close();
		system("pause");
		exit(0);
		break;
	case 1:
		library.Book_registration();
		break;
	case 2:
		library.Delete_books();
		break;
	case 3:
		library.Browse_books();
		break;
	case 4:
		library.Find_books();
		break;
	case 5:
		library.Borrowing_books();
		break;
	case 6:
		library.Return_books();
		break;
	case 7:
		printf("�� �鼮���� ��\n");
		library.Sort();
		break;
	default:
		printf("�� ERROR ��\n");
		break;
	}
}
int main() {
	library.init();
	while (1) {
		makeMenu();
		keyDown();
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}