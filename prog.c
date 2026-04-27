#include <stdio.h>
#include <string.h>
//حددنا حجم المخزن.
#define MAX 15 

typedef struct {
    char data[MAX];
    int head;  
    int tail;  
    int count;
} CircularBuffer;

//الدالة الأولى لإضافة حرف للمخزن.
void add(CircularBuffer *ay, char item) {
    if (ay->count < MAX) {
        ay->data[ay->head] = item;
        ay->head = (ay->head + 1) % MAX;
        ay->count++;
    } else {
        printf("\n[!] المخزن ممتلئ! لم يتم إضافة: %c", item);
    }
}
//الدالة الثانية لسحب حرف من المخزن.
char remove_item(CircularBuffer *ay) {
    if (ay->count > 0) {
        char item = 
ay->data[ay->tail];
        ay->tail = (ay->tail + 1) % MAX;
        ay->count--;
        return item;
    }
    return '\0'; 
}
//الدالة الرئيسية 
int main() {
    CircularBuffer myBuffer = {{0}, 0, 0, 0};
    char name[50];
//النص المراد إضافته على النص المُدخل.
 char extra[] = " CE-ESY";

//إدخال و طباعة النص.
    printf("ادخل النص: ");
    scanf("%s", name);

// إضافة عبارة " CE-ESY"
    strcat(name, extra); 

//تعبئة المخزن.
    printf("\n--- جاري التخزين ---\n");
    for (int i = 0; i < strlen(name); i++) {
        add(&myBuffer, name[i]);
    }

//قراءة البيانات من المخزن و عرضها.
    printf("\n\n--- جاري القراءة من المخزن ---\n");
    while (myBuffer.count > 0) {
        printf("%c", remove_item(&myBuffer));
    }
   printf("\n\nتمت العملية بنجاح والمخزن الآن فارغ.\n");

    return 0;
}
