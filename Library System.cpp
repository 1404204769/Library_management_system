#include "Library_System.h"
void library_system::insertByhead(BookInfo data) {//ͷ������
	List.push_back(data);
}
void library_system::insertBytail(BookInfo data) {//β������
	List.push_back(data);
}
list<BookInfo>::iterator library_system::searchByName(char* bookname) {//������������
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
void library_system::deleteNodeByName(char* bookname) {//��������ɾ��
	BookInfo Tem;
	for (list<BookInfo>::iterator it = List.begin(); it != List.end(); ++it) {
		Tem = *it;
		if (strcmp(Tem.name, bookname)==0) {
			List.erase(it);
			printf("ɾ���ɹ�!\n");
			return ;
		}
	}
	printf("ɾ��ʧ�ܣ�δ�ҵ����鼮!\n");
	return;
}
void library_system::printList() {//��ӡ��ʾ
	printf("����\t�۸�\t����\n");
	for (list<BookInfo>::iterator it = List.begin(); it != List.end(); ++it) {
		printf("%s\t%.1f\t%d\n", it->name, it->price, it->num);
	}
	return;
}
//�ļ�д����
void library_system::saveInfoToFile() {
	FILE* fp = fopen(filename, "w");
	for (list<BookInfo>::iterator it = List.begin(); it != List.end(); ++it) {
		fprintf(fp, "%s\t%.1f\t%d\n", it->name, it->price, it->num);
	}
	fclose(fp);
}
//�ļ�������
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
void library_system::init() {//ϵͳ��ʼ��
	readInfoFromFile();
}
void library_system::close() {//ϵͳ�ر�
	printf("�� �˳�ϵͳ ��\n");
	saveInfoToFile();
	List.clear();
	printf("�˳��ɹ�\n");
}
void library_system::Book_registration() {//�Ǽ��鼮
	printf("�� �Ǽ��鼮 ��\n");
	printf("�������鱾��Ϣ(name,price,num)\n");
	scanf("%s%f%d", &Temporary_books.name, &Temporary_books.price, &Temporary_books.num);
	insertBytail(Temporary_books);
}
void library_system::Delete_books() {//ɾ���鼮
	printf("�� ɾ���鼮 ��\n");
	printf("������Ҫɾ��������\n");
	scanf("%s", &Temporary_books.name);
	deleteNodeByName(Temporary_books.name);
	saveInfoToFile();
}
void library_system::Browse_books() {//����鼮
	printf("�� ����鼮 ��\n");
	printList();
}
void library_system::Find_books() {//�����鼮
	
	printf("�� �����鼮 ��\n");
	printf("������Ҫ���ҵ�����\n");
	scanf("%s", &Temporary_books.name);
	list<BookInfo>::iterator it= searchByName(Temporary_books.name);
	if (it == List.end()) {
		printf("δ�ҵ�����鼮\n");
	}
	else {
		printf("����\t�۸�\t����\n");
		printf("%s\t%.1f\t%d\n", it->name, it->price, it->num);
	}

}
void library_system::Borrowing_books() {//�����鼮
	printf("�� �����鼮 ��\n");
	printf("������Ҫ���ĵ�����\n");
	scanf("%s", &Temporary_books.name);
	list<BookInfo>::iterator it = searchByName(Temporary_books.name);
	if (it == List.end()) {
		printf("δ�ҵ�����鼮\n");
	}
	else {
		if (it->num) {
			it->num--;
			printf("�鼮���ĳɹ�\n");
		}
		else printf("��ǰ�鼮�޿�棬����ʧ��\n");
	}
}
void library_system::Return_books() {//�黹�鼮
	printf("�� �黹�鼮 ��\n");
	printf("������Ҫ�黹������\n");
	scanf("%s", &Temporary_books.name);
	list<BookInfo>::iterator it = searchByName(Temporary_books.name);
	if (it == List.end()) {
		printf("������Դ�Ƿ�\n");
	}
	else {
		it->num++;
		printf("�鼮�黹�ɹ���\n");
	}
}