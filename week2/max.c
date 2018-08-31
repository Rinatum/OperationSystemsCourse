#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("%li, %li, %li\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%i, %f, %lf\n", a, b, c);



    return 0;
}
