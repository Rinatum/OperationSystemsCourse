#include <stdio.h>
#include <string.h>

int main()
{
    printf("Vvedite n\n");
    int n;
    scanf("%d", &n);
    int k = 1;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++)
            printf(" ");
        for(int j = 0; j < k; j++)
            printf("*");
        for(int j = 0; j < i; j++)
            printf(" ");
        printf("\n");
        k = k + 2;
    }
    printf("%d", n);
    return 0;
}
