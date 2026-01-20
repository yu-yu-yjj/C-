#include "book.h"

// 修改图书
void updateBook() {
    printf("\n=== 修改图书 ===\n");
    
    if (head == NULL) {
        printf("当前没有图书记录！\n");
        return;
    }
    
    int id = getIntInput("请输入要修改的图书编号: ");
    Book *book = findBookById(id);
    
    if (book == NULL) {
        printf("未找到编号为 %d 的图书！\n", id);
        return;
    }
    
    printf("\n当前图书信息:\n");
    printBook(book);
    
    printf("\n请输入新的信息(不修改直接回车):\n");
    
    char input[MAX_LENGTH];
    
    // 修改名称
    getStringInput("图书名称: ", input, MAX_LENGTH);
    if (strlen(input) > 0) {
        strcpy(book->name, input);
    }
    
    // 修改作者
    getStringInput("作者: ", input, MAX_LENGTH);
    if (strlen(input) > 0) {
        strcpy(book->author, input);
    }
    
    // 修改价格
    printf("价格(当前 %.2f): ", book->price);
    fgets(input, MAX_LENGTH, stdin);
    if (strlen(input) > 1) { // 1是因为包含换行符
        book->price = atof(input);
    }
    
    // 修改出版日期
    getStringInput("出版日期: ", input, MAX_LENGTH);
    if (strlen(input) > 0) {
        strcpy(book->pub_date, input);
    }
    
    // 修改出版社
    getStringInput("出版社: ", input, MAX_LENGTH);
    if (strlen(input) > 0) {
        strcpy(book->publisher, input);
    }
    
    printf("图书信息修改成功！\n");
}
