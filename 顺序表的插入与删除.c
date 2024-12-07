// 顺序表的插入与删除
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//bool函数
#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int length;
}SqList;
// 初始化顺序表
void InitList(SqList* L) {
	L->length = 0;  // 初始化长度为 0
}
//删除顺序表内元素
bool ListDelete(SqList* L, int i, int e) {
	if (i<1 || i>L->length)

		return false;

	for (int j = i; j < L->length; j++) {

		L->data[j - 1] = L->data[j];

	}
	L->length--;

	return true;
}
//插入顺序表内元素
bool ListInsert(SqList *L, int i, int e) {
	// 检查插入位置是否有效
	if (i < 1 || i > L->length + 1) {
		
		return false;
	}

	// 检查是否有足够空间插入
	if (L->length >= MaxSize) {
		
		return false;
	}

	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;//data[i - 1]数组下标
	L->length++;
	return true;
}
// 打印顺序表的元素
void PrintList(SqList* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d", L->data[i]);
			
	}
	printf("\n");
}
int main()
{
	SqList L;
	InitList(&L);
	int data[MaxSize] = { 1,2,4,5,6 };
	L.length = 5;// 顺序表当前有 5 个元素
	for (int i = 0; i < L.length; i++) {
		L.data[i] = data[i];
	}
		// 插入元素 3 到位置 3
    if(ListInsert(&L, 3, 3)) {
		printf("插入成功！\n");
	} else {
	 printf("插入失败！\n");
	}
	// 删除元素 3 到位置 3
    if(ListDelete(&L, 3, 3)) {
		printf("删除成功！\n");
	} else {
	 printf("删除失败！\n");
	}
	// 打印顺序表的元素
	PrintList(&L);
	return 0;
}
