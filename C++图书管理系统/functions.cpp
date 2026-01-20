#include "book.h"

void loadFromFile(){
	FILE *file = fopen("books.txt", "rb");
    if (!file) {
        printf("无法打开文件或文件不存在\n");
        return;
    }

    Book temp;
    while (fread(&temp, sizeof(Book), 1, file)) {
        Book *newBook = (Book*)malloc(sizeof(Book));
        *newBook = temp;
        newBook->next = head;
        head = newBook;
    }
    fclose(file);
}
 
void saveToFile(){
	FILE *file = fopen("books.txt", "wb");
    if (!file) {
        printf("无法创建文件\n");
        return;
    }

    Book *current = head;
    while (current) {
        fwrite(current, sizeof(Book), 1, file);
        current = current->next;
    }
    fclose(file);
}
 

void clearInputBuffer(){
	while (getchar() != '\n');
}

void printBook(Book *book){
	if (!book) return;
    printf("ID: %d\n书名: %s\n作者: %s\n价格: %.2f\n出版日期：%s\n出版社：%s\n\n", 
           book->id, book->name, book->author, book->price,book->pub_date,book->publisher);
}

Book* findBookById(int id){
	Book *current = head;
    while (current) {
        if (current->id == id) return current;
        current = current->next;
    }
    return NULL; 
}
int getIntInput(const char *prompt){
	int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        clearInputBuffer();
        printf("输入无效，请重新输入: ");
    }
    clearInputBuffer();
    return value;
}
float getFloatInput(const char *prompt){
	float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1) {
        clearInputBuffer();
        printf("输入无效，请重新输入: ");
    }
    clearInputBuffer();
    return value;
}
void getStringInput(const char *prompt, char *buffer, int size){
	printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

