#include "Dui.h"
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdJustUp(HPDataType* a, int n, int child)  //�������������飬Ԫ�ظ�����Ҫ����Ԫ�ص��±�
{
	int parent = (child - 1) / 2;              //������ĸ��׽ڵ���±�
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

void AdJustDown(HPDataType* a,int n, int parent)	    //�ӵ�һ����Ҷ�ڵ���е���
{
	int child = parent * 2 + 1;      //����
	while (child < n)
	{
		if ((child + 1)<n && a[child] > a[child + 1])
			child++;                                     
		if (a[child] < a[parent])                     //����֮��child���ǽϴ��ӵ��±�
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)    //��ʼ��     n������Ԫ�ظ���
{
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n*2);  //_a��ָ�룬����ά������a
	hp->capacity = n*2;
	hp->size = 0;
	int i = 0;
	for (i=0; i < n; i++)                //�����鸴�Ƶ����ٵ��ڴ���ȥ
	{
		hp->_a[i] = a[i];
		hp->size++;
	}
	//����
	for (i = (n-2)/2; i >= 0;i--)              //(n-2)/2�����һ����Ҷ�ڵ��˫�׽ڵ���±�
	{
		AdJustDown(hp->_a,hp->size, i);
	}
}

void HeapDestory(Heap* hp)                      //����
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
			perror("���ٿռ�ʧ��:");
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

void HeapSort(HPDataType* a, int n)             //������
{
	assert(a);
	int i = 0;
	int end = n - 1;
	//����
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdJustDown(a, n, i);                   
	}                                      //�Ƚ���������ɴ�С����
	while (end > 0)
	{
		Swap(&a[0], &a[end]);              //����ѣ�����Ԫ��Ϊ����  ����С�ѣ���֮
		AdJustDown(a, end, 0);             //�ٽ�ʣ�µ�Ԫ���ٵ����ɴ�С���ѣ�
		end--;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void HeapTopK(HPDataType* arr, int n, int k)                    //TopK����
{
	assert(arr);
	Heap hp;
	hp._a = (HPDataType*)malloc(sizeof(HPDataType)*k);      //_a��ָ�룬����ά������a
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
	//С��
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