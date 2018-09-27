#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#define N 1000
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);    //初始化
void HeapDestory(Heap* hp);                       //销毁
void PrintHeap(Heap* hp, int n);                  //打印

void PushHeap(Heap* hp, HPDataType x);	   
void PopHeap(Heap* hp);	   
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
HPDataType HeapTop(Heap* hp);    

void HeapSort(HPDataType* a, int n);             //堆排序
void HeapTopK(HPDataType* a, int n, int k);                    //TopK问题

void AdJustUp(HPDataType* a, int n, int child);      //从child元素，向上调整成大（小）堆
void AdJustDown(HPDataType* a, int n, int child);    //从parent元素，向下调整成大（小）堆

