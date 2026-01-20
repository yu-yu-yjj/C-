#include "book.h"

// 查询图书
void queryBook() {
    printf("\n=== 查询图书 ===\n");
    
    if (head == NULL) {
        printf("当前没有图书记录！\n");
        return;
    }
    
    int choice;
    printf("1. 按编号查询\n");
    printf("2. 按名称查询\n");
    printf("3. 按作者查询\n");
    printf("请选择查询方式: ");
    scanf("%d", &choice);
    clearInputBuffer();
    
    char keyword[MAX_LENGTH];
    Book *current = head;
    bool found = false;
    
    switch (choice) {
        case 1: {
            int id = getIntInput("请输入图书编号: ");
            Book *book = findBookById(id);
            if (book != NULL) {
                printf("\n查询结果:\n");
                printBook(book);
                found = true;
            }
            break;
        }
        case 2:
            getStringInput("请输入图书名称: ", keyword, MAX_LENGTH);
            printf("\n查询结果:\n");
            while (current != NULL) {
                if (strstr(current->name, keyword) != NULL) {
                    printBook(current);
                    found = true;
                }
                current = current->next;
            }
            break;
        case 3:
            getStringInput("请输入作者: ", keyword, MAX_LENGTH);
            printf("\n查询结果:\n");
            while (current != NULL) {
                if (strstr(current->author, keyword) != NULL) {
                    printBook(current);
                    found = true;
                }
                current = current->next;
            }
            break;
        default:
            printf("无效选择！\n");
            return;
    }
    
    if (!found) {
        printf("未找到匹配的图书！\n");
    }
}

// 浏览图书(分页)
void browseBooks() {
    printf("\n=== 浏览图书 ===\n");
    
    if (head == NULL) {
        printf("当前没有图书记录！\n");
        return;
    }
    
    int page = 1;
    int total = 0;
    Book *current = head;
    
    // 计算总记录数
    while (current != NULL) {
        total++;
        current = current->next;
    }
    
    int totalPages = (total + PAGE_SIZE - 1) / PAGE_SIZE;
    
    char input;
    do {
        // 显示当前页内容
        printf("\n=== 第 %d 页(共 %d 页) ===\n", page, totalPages);
        
        int startIdx = (page - 1) * PAGE_SIZE;
        int count = 0;
        current = head;
        
        // 定位到当前页起始位置
        for (int i = 0; i < startIdx && current != NULL; i++) {
            current = current->next;
        }
        
        // 显示当前页的图书
        while (current != NULL && count < PAGE_SIZE) {
            printBook(current);
            current = current->next;
            count++;
        }
        
        // 显示分页导航
        printf("\n[%d/%d] ", page, totalPages);
        if (page > 1) {
            printf("(P)上一页 ");
        }
        if (page < totalPages) {
            printf("(N)下一页 ");
        }
        printf("(Q)返回主菜单\n");
        printf("请选择操作: ");
        
        scanf(" %c", &input);
        clearInputBuffer();
        
        // 处理用户输入
        switch (toupper(input)) {
            case 'P':
                if (page > 1) page--;
                break;
            case 'N':
                if (page < totalPages) page++;
                break;
            case 'Q':
                return;
            default:
                printf("无效输入，请重新选择\n");
        }
    } while (1);
}
