#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        if ((long long)i * i % n == 1)
            printf("%d\n", i);
    return 0;
}