#include "book.h"

// 添加图书
void addBook() {
    printf("\n=== 添加图书 ===\n");
    
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("内存分配失败！\n");
        return;
    }
    
    // 输入图书信息
    newBook->id = getIntInput("请输入图书编号: ");
    
    // 检查编号是否已存在
    if (findBookById(newBook->id) != NULL) {
        printf("该编号已存在，添加失败！\n");
        free(newBook);
        return;
    }
    
    getStringInput("请输入图书名称: ", newBook->name, MAX_LENGTH);
    getStringInput("请输入作者: ", newBook->author, MAX_LENGTH);
    newBook->price = getFloatInput("请输入价格: ");
    getStringInput("请输入出版日期(YYYY-MM-DD): ", newBook->pub_date, MAX_LENGTH);
    getStringInput("请输入出版社: ", newBook->publisher, MAX_LENGTH);
    
    // 插入链表头部
    newBook->next = head;
    head = newBook;
    
    printf("图书添加成功！\n");
}
