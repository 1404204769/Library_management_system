#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<list>
using namespace std;

#define DB "BookDatabase.txt"
struct BookInfo {
	char name[20];
	float price;
	int num;
};
BookInfo Temporary_books;//临时存放书本信息
struct Node {
	BookInfo data;
	Node* next;
};
Node* head;
//创建链表头节点
Node* creatHead() {
	Node* newNode = (struct Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	return newNode;
}
//创建链表结点
Node* creatNode(BookInfo& data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
Node* searchByName(Node* headNode, char* bookname) {
	Node* posNode = headNode->next;
	while (posNode && strcmp(posNode->data.name, bookname)) {
		posNode = posNode->next;
	}
	return posNode;
}


//头部插入
void insertByhead(Node* headNode, BookInfo data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = headNode->next;
	newNode->data = data;
	headNode->next = newNode;
}
//尾部插入
void insertBytail(Node* headNode, BookInfo data) {
	while (headNode->next) {
		headNode = headNode->next;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = headNode->next;
	newNode->data = data;
	headNode->next = newNode;
}

void deleteNodeByName(Node* headNode, char* posName) {
	Node* posleftNode = headNode;
	Node* posNode = headNode->next;
	while (posNode && strcmp(posNode->data.name, posName)) {
		posleftNode = posNode;
		posNode = posNode->next;
	}
	//如果没找到就直接返回
	if (posNode == NULL) {
		return;
	}
	else {
		posleftNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
		printf("删除成功!\n");
	}
}
void printList(Node* headNode) {
	Node* posNode = headNode->next;
	printf("书名\t价格\t数量\n");
	while (posNode) {
		printf("%s\t%.1f\t%d\n", posNode->data.name, posNode->data.price, posNode->data.num);
		posNode = posNode->next;
	}
}
void bubbleSort(Node* headNode) {
	for (Node* posNode = headNode->next; posNode; posNode = posNode->next) {
		for (Node* desNode = headNode->next; desNode->next; desNode = desNode->next) {
			if (desNode->data.price > desNode->next->data.price) {
				Temporary_books = desNode->data;
				desNode->data = desNode->next->data;
				desNode->next->data = Temporary_books;
			}
		}
	}
}
//文件操作存储数据
//文件写操作
void saveInfoToFile(const char* filename, Node* headNode) {
	FILE* fp = fopen(filename, "w");
	Node* posNode = headNode->next;
	while (posNode) {
		fprintf(fp, "%s\t%.1f\t%d\n", posNode->data.name, posNode->data.price, posNode->data.num);
		posNode = posNode->next;
	}
	fclose(fp);
}
//文件读操作
void readInfoFromFile(const char* filename, Node* headNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w+");
	}
	while (fscanf(fp, "%s\t%f\t%d\n", &Temporary_books.name, &Temporary_books.price, &Temporary_books.num) != EOF) {
		insertBytail(headNode, Temporary_books);
	}
	fclose(fp);
}