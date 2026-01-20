#include "book.h"

Book *head = NULL; // 初始化链表头指针

// 初始化系统
void initSystem() {
    loadFromFile();
}

// 登录功能
bool login() {
    char password[MAX_LENGTH];
    int attempts = 3;
    
    while (attempts > 0) {
        printf("\n=== 图书管理系统登录 ===\n");
        printf("请输入密码(剩余尝试次数 %d): ", attempts);
        
        // 密码输入隐藏
        int i = 0;
        char ch;
        while ((ch = _getch()) != '\r') { // 回车结束
            if (ch == '\b') { // 退格处理
                if (i > 0) {
                    printf("\b \b");
                    i--;
                }
            } else {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        printf("\n");
        
        if (strcmp(password, PASSWORD) == 0) {
            return true;
        } else {
            printf("密码错误！\n");
            attempts--;
        }
    }
    
    printf("登录失败，系统退出！\n");
    return false;
}

// 主菜单
void mainMenu() {
    int choice;
    
    do {
        printf("\n=== 图书管理系统 ===\n");
        printf("1. 添加图书\n");
        printf("2. 删除图书\n");
        printf("3. 修改图书\n");
        printf("4. 查询图书\n");
        printf("5. 浏览图书\n");
        printf("6. 保存数据到文件\n");
        printf("0. 退出系统\n");
        printf("请选择操作: ");
        
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: deleteBook(); break;
            case 3: updateBook(); break;
            case 4: queryBook(); break;
            case 5: browseBooks(); break;
            case 6: saveToFile(); break;
            case 0: 
                printf("感谢使用，再见！\n");
                break;
            default:
                printf("无效选择，请重新输入！\n");
        }
    } while (choice != 0);
}

int main() {
    if (!login()) {
        return 0;
    }
    
    initSystem();
    mainMenu();
    
    // 退出前保存数据
    saveToFile();
    
    // 释放链表内存
    Book *current = head;
    while (current != NULL) {
        Book *temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
