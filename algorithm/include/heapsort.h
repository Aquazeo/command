#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void swap(int *lhs, int *rhs)
{
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
	return;
}

void max_heapfy(int A[], int p, int n)
{
	int l, r;
	l = 2 * p;
	r = l + 1;

	if (l > n) return;
	else if (r > n)
	{
		if (A[l] > A[p])
			swap(&A[p], &A[l]);
		return;
	}
	if (A[l] > A[p])
	{
		if (A[r] > A[l])
		{
			swap(&A[p], &A[r]);
			max_heapfy(A, r, n);
		}

		else
		{
			swap(&A[p], &A[l]);
			max_heapfy(A, l, n);
		}
	}
	else if (A[r] > A[p])
	{
		swap(&A[p], &A[r]);
		max_heapfy(A, r, n);
	}
	return;
}

void build_maxheap(int A[], int n)
{
	for (int i = n / 2; i >= 1; i --)
		max_heapfy(A, i, n);
	return;
}

void heap_sort(int A[], int n)
{
	for (int i = n; i >= 2; i --)
	{
		build_maxheap(A, i);
		swap(&A[1], &A[i]);
	}
	return;
}

#endif
