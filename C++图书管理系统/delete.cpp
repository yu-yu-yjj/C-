#include "book.h"

// 删除图书
void deleteBook() {
    printf("\n=== 删除图书 ===\n");
    
    if (head == NULL) {
        printf("当前没有图书记录！\n");
        return;
    }
    
    int id = getIntInput("请输入要删除的图书编号: ");
    
    Book *current = head;
    Book *prev = NULL;
    
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                // 删除头节点
                head = current->next;
            } else {
                prev->next = current->next;
            }
            
            free(current);
            printf("图书删除成功！\n");
            return;
        }
        
        prev = current;
        current = current->next;
    }
    
    printf("未找到编号为 %d 的图书！\n", id);
}
