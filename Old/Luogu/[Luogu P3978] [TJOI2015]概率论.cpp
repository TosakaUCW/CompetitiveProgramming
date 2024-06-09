#include <stdio.h>

double n;

int main()
{
    scanf("%lf", &n);
    printf("%.9f", n * (n + 1) / (2 * (2 * n - 1)));
    return 0;
}