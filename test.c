#include "Dui.h"
void testTopK()
{
	HPDataType arr[N];
	int i = 0;
	for (i = 0; i < N; i++)
	{
		arr[i] = rand() % 10000;
	}
	arr[0] = 10000;
	arr[99] = 12345;
	arr[120] = 15896;
	arr[500] = 78945;
	arr[999] = 81000;
	HeapTopK(arr, N, 5);
}

int main()
{
	/*Heap hp;
	HPDataType arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int len = sizeof(arr) / sizeof(arr[0]);
	HeapInit(&hp, arr, len);*/
	//PushHeap(&hp, 100);
	//PopHeap(&hp);
	//printf("%d ", HeapSize(&hp));
	//printf("%d ", HeapEmpty(&hp));
	//printf("%d ",HeapTop(&hp));
	//HeapSort(arr, len);             //¶ÑÅÅÐò
	//printf("\n");
	//PrintHeap(&hp,hp.size);
	testTopK();
	return 0;
}
