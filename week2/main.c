#include <stdio.h>
#include <string.h>

int main()
{
    printf("Vvedite stroku\n");
    char arr[100], arr_reverse[100];
    gets(arr);
    long int i = 0;
    for(i = strlen(arr) - 1;i >= 0; i--)
        arr_reverse[strlen(arr) - 1 - i] = arr[i];
    printf("%s",arr_reverse);

    return 0;
}

