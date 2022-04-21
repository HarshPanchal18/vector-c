/*
Dynamic array(vector) in С that works with any data structure and does some basic type checking
https://github.com/i1i1/vector
*/

#include <stdio.h>
#include <stdlib.h>
#define VECTOR_IMPLEMENTATION
#include "vector.h"

int cmp(int *a, int *b)
{
    return *a - *b;
}

int main(void)
{
    vector_decl(int, a);
    int i, sum = 0;

    for (i = 99; i >= 0; i--)
        if (vector_push(&a, i))
            return 1;

    for (i = 0; i < (int)vector_nmemb(&a); i++)
    {
        sum += a[i];
        printf("%d:%d\t", i, a[i]);
    }

    printf("\nSum is equal to %d\nTotal elements %d", sum, vector_nmemb(&a));

    qsort(a, vector_nmemb(&a), sizeof(int), (void *)cmp);

    for (i = 0; i < (int)vector_nmemb(&a); i++)
        printf("%d:%d\t", i, a[i]);

    printf("\n");

    while (vector_nmemb(&a))
        printf("%d\t", vector_pop(&a));

    printf("\n");
    vector_free(&a);
}
