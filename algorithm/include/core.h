#ifndef CORE_H
#define CORE_H

void swap(int *lhs, int *rhs)
{
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
	return;
}

#endif
