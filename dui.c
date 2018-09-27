#include "Dui.h"
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdJustUp(HPDataType* a, int n, int child)  //三个参数：数组，元素个数，要调整元素的下标
{
	int parent = (child - 1) / 2;              //算出它的父亲节点的下标
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void AdJustDown(HPDataType* a,int n, int parent)	    //从第一个非叶节点进行调整
{
	int child = parent * 2 + 1;      //左孩子
	while (child < n)
	{
		if ((child + 1)<n && a[child] > a[child + 1])
			child++;                                     
		if (a[child] < a[parent])                     //出来之后child总是较大孩子的下标
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)    //初始化     n是数组元素个数
{
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n*2);  //_a是指针，用来维护数组a
	hp->capacity = n*2;
	hp->size = 0;
	int i = 0;
	for (i=0; i < n; i++)                //把数组复制到开辟的内存中去
	{
		hp->_a[i] = a[i];
		hp->size++;
	}
	//调堆
	for (i = (n-2)/2; i >= 0;i--)              //(n-2)/2是最后一个非叶节点的双亲节点的下标
	{
		AdJustDown(hp->_a,hp->size, i);
	}
}

void HeapDestory(Heap* hp)                      //销毁
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

void PushHeap(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int a = hp->capacity + 10;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*a);
		if (tmp)
		{
			hp->_a = tmp;
			hp->capacity = a;
		}
		else
			perror("开辟空间失败:");
	}
	hp->size++;
	hp->_a[hp->size - 1] = x;
	AdJustUp(hp->_a, hp->size, hp->size - 1);
}

void PopHeap(Heap* hp)
{
	assert(hp);
	Swap(&hp->_a[0], &hp->_a[hp->size - 1]);
	hp->size--;
	int i = 0;
	AdJustDown(hp->_a, hp->size, i);
	
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size > 0 ? 1 : 0;
}

HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

void PrintHeap(Heap* hp,int n)
{
	assert(hp);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void HeapSort(HPDataType* a, int n)             //堆排序
{
	assert(a);
	int i = 0;
	int end = n - 1;
	//调堆
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdJustDown(a, n, i);                   
	}                                      //先将数组调整成大（小）堆
	while (end > 0)
	{
		Swap(&a[0], &a[end]);              //（大堆）其首元素为最大的  ；（小堆）反之
		AdJustDown(a, end, 0);             //再将剩下的元素再调整成大（小）堆；
		end--;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void HeapTopK(HPDataType* arr, int n, int k)                    //TopK问题
{
	assert(arr);
	Heap hp;
	hp._a = (HPDataType*)malloc(sizeof(HPDataType)*k);      //_a是指针，用来维护数组a
	hp.capacity = k;
	hp.size = 0;
	int i;
	for ( i = 0; i < k; i++)
	{
		hp._a[i] = arr[i];
		hp.size++;
	}
	for (i = (k - 2) / 2; i >= 0; i--)
	{
		AdJustDown(hp._a, k, i);
	}
	//小堆
	for (i = k; i < n; i++)
	{
		if (arr[i]>HeapTop(&hp))
		{
			PopHeap(&hp);
			PushHeap(&hp, arr[i]);
		}
	}
	HeapSort(hp._a, k);
	printf("\n");
	PrintHeap(&hp, k);
}