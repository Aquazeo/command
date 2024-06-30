#include <stdio.h>
#include "heapsort.h"

void scan_array(int A[], int p, int q)
{
	for (int i = p; i <= q; i ++)
	{
		scanf("%d", &A[i]);
	}
	return;
}

void print_array(int A[], int p, int q)
{
	for (int i = p; i <= q; i ++)
	{
		printf("%d ", A[i]);
	}
	return;
}

int main(void)
{
	const int N = 11;
	int a[N];
	
	scan_array(a, 1, N - 1);
	heap_sort(a, N - 1);
	print_array(a, 1, N - 1);	
	puts("");

	return 0;
}
