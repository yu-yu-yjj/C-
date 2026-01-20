#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h> // 用于密码输入

#define MAX_LENGTH 100
#define PASSWORD "123456" // 默认密码
#define PAGE_SIZE 5       // 每页显示5条记录

// 图书结构体
typedef struct Book {
    int id;                     // 编号
    char name[MAX_LENGTH];      // 名称
    char author[MAX_LENGTH];    // 作者
    float price;                // 价格
    char pub_date[MAX_LENGTH];  // 出版日期
    char publisher[MAX_LENGTH]; // 出版社
    struct Book *next;          // 指向下一本书的指针
} Book;

// 全局变量 - 链表头指针
extern Book *head;

// 函数声明
void initSystem();
bool login();
void saveToFile();
void loadFromFile();
void mainMenu();

// 图书操作函数
void addBook();
void deleteBook();
void updateBook();
void queryBook();
void browseBooks();

// 辅助函数
void clearInputBuffer();
void printBook(Book *book);
Book* findBookById(int id);
int getIntInput(const char *prompt);
float getFloatInput(const char *prompt);
void getStringInput(const char *prompt, char *buffer, int size);

#endif // BOOK_H
