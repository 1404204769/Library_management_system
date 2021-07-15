#pragma once
#ifndef _LIBRARY_SYSTEM_H
#define _LIBRARY_SYSTEM_H
#include<list>
using namespace std;
struct BookInfo {
	char name[20];
	float price;
	int num;
};
struct Compare {
	bool operator()(const BookInfo& A, const BookInfo& B) {
		return A.price > B.price;
	}
};
class library_system {
	const char* const filename = "BookDatabase.txt";
	list<BookInfo>List;
	BookInfo Temporary_books;
	BookInfo* result;
public:
	void init();//系统初始化
	void close();//系统关闭
	void Book_registration();//登记书籍
	void Delete_books();//删除书籍
	void Browse_books();//浏览书籍
	void Find_books();//查找书籍
	void Borrowing_books();//借阅书籍
	void Return_books();//归还书籍
	void insertByhead(BookInfo data);//头部插入
	void insertBytail(BookInfo data);//尾部插入
	list<BookInfo>::iterator searchByName(char* bookname);//根据书名查找
	void deleteNodeByName(char* bookname);//根据书名删除
	void printList();//打印显示
	void Sort() {
		List.sort(Compare());
	}
	//文件操作存储数据
	void saveInfoToFile();//文件写操作
	void readInfoFromFile();//文件读操作
};

#endif // !_LIBRARY_SYSTEM_H

