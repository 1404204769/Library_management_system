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
	void init();//ϵͳ��ʼ��
	void close();//ϵͳ�ر�
	void Book_registration();//�Ǽ��鼮
	void Delete_books();//ɾ���鼮
	void Browse_books();//����鼮
	void Find_books();//�����鼮
	void Borrowing_books();//�����鼮
	void Return_books();//�黹�鼮
	void insertByhead(BookInfo data);//ͷ������
	void insertBytail(BookInfo data);//β������
	list<BookInfo>::iterator searchByName(char* bookname);//������������
	void deleteNodeByName(char* bookname);//��������ɾ��
	void printList();//��ӡ��ʾ
	void Sort() {
		List.sort(Compare());
	}
	//�ļ������洢����
	void saveInfoToFile();//�ļ�д����
	void readInfoFromFile();//�ļ�������
};

#endif // !_LIBRARY_SYSTEM_H

