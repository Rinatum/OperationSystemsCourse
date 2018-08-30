#include <stdio.h>
#include <string.h>


void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    printf("Vvedite a and b\n");
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d", a);
    printf("   %d\n", b);
    swap(&a, &b);
    printf("%d", a);
    printf("   %d\n", b);
    return 0;
}

