#include<stdio.h>
#include "Library_System.h"
library_system library;
//1.写界面---->菜单---->模块
void makeMenu() {
	printf("-----------------------------------\n");
	printf("         图书管理系统\n");
	printf("\t0.退出系统\n");
	printf("\t1.登记书籍\n");
	printf("\t2.删除书籍\n");
	printf("\t3.浏览书籍\n");
	printf("\t4.查找书籍\n");
	printf("\t5.借阅书籍\n");
	printf("\t6.归还书籍\n");
	printf("\t7.书籍排序\n");
	printf("-----------------------------------\n");
	printf("请输入(0~7):");
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
		printf("【 书籍排序 】\n");
		library.Sort();
		break;
	default:
		printf("【 ERROR 】\n");
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