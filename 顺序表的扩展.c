顺序表的定义
#include <stdio.h>
#include <stdlib.h>

#define InitSize 10 // 默认最大长度

// 定义结构体
typedef struct {
    int* data;
    int MaxSize;
    int length;
} SeqList;

// 初始化顺序表
void InitList(SeqList* L) {
    // 用 malloc 函数申请一片连续的存储空间
    L->data = (int*)malloc(InitSize * sizeof(int));
    if (L->data == NULL) {  // 检查内存分配是否成功
        printf("Memory allocation failed!\n");
        exit(1); // 如果分配失败，退出程序
    }
    L->length = 0;
    L->MaxSize = InitSize;
}

// 扩展顺序表空间
void IncreaseSize(SeqList* L, int len) {
    int* p = L->data; // 保存原来的数据区域
    L->data = (int*)malloc((L->MaxSize + len) * sizeof(int)); // 申请新的内存
    if (L->data == NULL) {  // 检查内存分配是否成功
        printf("Memory allocation failed!\n");
        free(p);  // 释放原来的内存
        exit(1); // 如果分配失败，退出程序
    }
    for (int i = 0; i < L->length; i++) {
        L->data[i] = p[i]; // 将数据复制到新的区域
    }
    L->MaxSize = L->MaxSize + len; // 更新最大容量
    free(p); // 释放原内存
}

int main() {
    SeqList L; // 声明顺序表
    InitList(&L); // 初始化顺序表
    IncreaseSize(&L, 5); // 扩展顺序表空间

    // 可根据需要继续使用 L，如添加数据等操作
    printf("MaxSize: %d\n", L.MaxSize);
    printf("Length: %d\n", L.length);

    // 释放分配的内存
    free(L.data);

    return 0;
}
