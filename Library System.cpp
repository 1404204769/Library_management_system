#include "Library_System.h"
void library_system::insertByhead(BookInfo data) {//头部插入
	List.push_back(data);
}
void library_system::insertBytail(BookInfo data) {//尾部插入
	List.push_back(data);
}
list<BookInfo>::iterator library_system::searchByName(char* bookname) {//根据书名查找
	BookInfo Tem;
	for (list<BookInfo>::iterator it = List.begin(); it != List.end(); ++it) {
		Tem = *it;
		if (strcmp(Tem.name, bookname) == 0) {
			Temporary_books = Tem;
			return it;
		}
	}
	return List.end();
}
void library_system::deleteNodeByName(char* bookname) {//根据书名删除
	BookInfo Tem;
	for (list<BookInfo>::iterator it = List.begin(); it != List.end(); ++it) {
		Tem = *it;
		if (strcmp(Tem.name, bookname)==0) {
			List.erase(it);
			printf("删除成功!\n");
			return ;
		}
	}
	printf("删除失败，未找到此书籍!\n");
	return;
}
void library_system::printList() {//打印显示
	printf("书名\t价格\t数量\n");
	for (list<BookInfo>::iterator it = List.begin(); it != List.end(); ++it) {
		printf("%s\t%.1f\t%d\n", it->name, it->price, it->num);
	}
	return;
}
//文件写操作
void library_system::saveInfoToFile() {
	FILE* fp = fopen(filename, "w");
	for (list<BookInfo>::iterator it = List.begin(); it != List.end(); ++it) {
		fprintf(fp, "%s\t%.1f\t%d\n", it->name, it->price, it->num);
	}
	fclose(fp);
}
//文件读操作
void library_system::readInfoFromFile() {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w+");
	}
	while (fscanf(fp, "%s\t%f\t%d\n", &Temporary_books.name, &Temporary_books.price, &Temporary_books.num) != EOF) {
		insertBytail(Temporary_books);
	}
	fclose(fp);
}
void library_system::init() {//系统初始化
	readInfoFromFile();
}
void library_system::close() {//系统关闭
	printf("【 退出系统 】\n");
	saveInfoToFile();
	List.clear();
	printf("退出成功\n");
}
void library_system::Book_registration() {//登记书籍
	printf("【 登记书籍 】\n");
	printf("请输入书本信息(name,price,num)\n");
	scanf("%s%f%d", &Temporary_books.name, &Temporary_books.price, &Temporary_books.num);
	insertBytail(Temporary_books);
}
void library_system::Delete_books() {//删除书籍
	printf("【 删除书籍 】\n");
	printf("请输入要删除的书名\n");
	scanf("%s", &Temporary_books.name);
	deleteNodeByName(Temporary_books.name);
	saveInfoToFile();
}
void library_system::Browse_books() {//浏览书籍
	printf("【 浏览书籍 】\n");
	printList();
}
void library_system::Find_books() {//查找书籍
	
	printf("【 查找书籍 】\n");
	printf("请输入要查找的书名\n");
	scanf("%s", &Temporary_books.name);
	list<BookInfo>::iterator it= searchByName(Temporary_books.name);
	if (it == List.end()) {
		printf("未找到相关书籍\n");
	}
	else {
		printf("书名\t价格\t数量\n");
		printf("%s\t%.1f\t%d\n", it->name, it->price, it->num);
	}

}
void library_system::Borrowing_books() {//借阅书籍
	printf("【 借阅书籍 】\n");
	printf("请输入要借阅的书名\n");
	scanf("%s", &Temporary_books.name);
	list<BookInfo>::iterator it = searchByName(Temporary_books.name);
	if (it == List.end()) {
		printf("未找到相关书籍\n");
	}
	else {
		if (it->num) {
			it->num--;
			printf("书籍借阅成功\n");
		}
		else printf("当前书籍无库存，借阅失败\n");
	}
}
void library_system::Return_books() {//归还书籍
	printf("【 归还书籍 】\n");
	printf("请输入要归还的书名\n");
	scanf("%s", &Temporary_books.name);
	list<BookInfo>::iterator it = searchByName(Temporary_books.name);
	if (it == List.end()) {
		printf("该书来源非法\n");
	}
	else {
		it->num++;
		printf("书籍归还成功！\n");
	}
}