#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

int main(int argc, char **argv)
{
    int array[argc];

    for (int i = 1; i < argc; i ++ )
    {
        array[i] = atoi(argv[i]);
    }

    heap_sort(array, argc - 1);

    for (int i = 1; i < argc; i ++ )
    {
        printf("%d ", array[i]);
    }
    puts("");

    return 0;
}
