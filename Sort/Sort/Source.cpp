#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
/// 1、冒泡排序算法
void popSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}

//////////////////////////////////////////////////////////////////////////
/// 2、插入排序算法
void insertSort(int *arr, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int t = arr[i];
		for (j = i; j > 0 && (t < arr[j - 1]); j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = t;
	}
}

//////////////////////////////////////////////////////////////////////////
/// 3、希尔排序算法  插入排序的衍生
void shellSort(int *arr, int n)
{
	int gap = n / 2;
	while (gap >= 1)
	{
		int i, j, t;
		for (i = gap; i < n; i++)
		{
			t = arr[i];
			for (j = i; j > 0 && t < arr[j - gap]; j = j - gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = t;
		}
		gap = gap / 2;
	}
}

//////////////////////////////////////////////////////////////////////////
///  4、选择排序
void selectSort(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
/// 选择排序优化版本
void selectSortOptmize(int * arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int idx = i;

		for (int j = idx + 1; j < n; j++)
		{
			if (arr[idx] > arr[j])
				idx = j;
		}
		if (idx != i)
		{
			arr[i] ^= arr[idx];
			arr[idx] ^= arr[i];
			arr[i] ^= arr[idx];
		}
	}
}

//////////////////////////////////////////////////////////////////////////
/// 5、快速排序
void quickSort(int *arr, int left, int right)
{
	if (left < right)
	{
		int l = left, h = right;
		int pivot = arr[l];

		while (l < h)
		{
			while (pivot <= arr[h] && l < h)
				h--;
			arr[l] = arr[h];

			while (pivot >= arr[l] && l < h)
				l++;
			arr[h] = arr[l];
		}
		arr[l] = pivot;

		quickSort(arr, left, l - 1);
		quickSort(arr, l + 1, right);
	}
}

///  6、归并排序算法
void mergeArr(int *src, int *tmp, int start, int mid, int end)
{
	int i = start, j = mid + 1;
	int k = start;
	while (i != mid + 1 && j != end + 1)
	{
		if (src[i] < src[j])
			tmp[k++] = src[i++];
		else
			tmp[k++] = src[j++];
	}
	if (i == mid + 1)
		while (j != end + 1)
			tmp[k++] = src[j++];
	else
		while (i != mid + 1)
			tmp[k++] = src[i++];

	//while (start != end)
	for (start; start < end + 1; start = start + 1)
	{
		src[start] = tmp[start];
	}

}

void mergeSort(int *src, int *tmp, int start, int end)
{

	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(src, tmp, start, mid);
		mergeSort(src, tmp, mid + 1, end);
		mergeArr(src, tmp, start, mid, end);
	}
}


//////////////////////////////////////////////////////////////////////////
/// 数据打印

void dis(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main(int argc, char *argv[])
{
	int arr[] = { 89,4,69,288,10,1,3,5,7,9 };

	int c[10];

	//int arr[] = {2,0,1,8,3,6,7,9};
	//popSort(arr,sizeof(arr)/sizeof(*arr));
	//insertSort(arr,sizeof(arr)/sizeof(*arr ));
	//shellSort(arr, sizeof(arr) / sizeof(*arr));
	//mergeSort(arr, c, 0, 9);
	//selectSortOptmize(arr, sizeof(arr) / sizeof(*arr));

	quickSort(arr, 0, 9);

	dis(arr, sizeof(arr) / sizeof(*arr));

	system("pause");
	return 0;
}
