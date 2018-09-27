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

void HeapInit(Heap* hp, HPDataType* a, int n);    //��ʼ��
void HeapDestory(Heap* hp);                       //����
void PrintHeap(Heap* hp, int n);                  //��ӡ

void PushHeap(Heap* hp, HPDataType x);	   
void PopHeap(Heap* hp);	   
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
HPDataType HeapTop(Heap* hp);    

void HeapSort(HPDataType* a, int n);             //������
void HeapTopK(HPDataType* a, int n, int k);                    //TopK����

void AdJustUp(HPDataType* a, int n, int child);      //��childԪ�أ����ϵ����ɴ�С����
void AdJustDown(HPDataType* a, int n, int child);    //��parentԪ�أ����µ����ɴ�С����

