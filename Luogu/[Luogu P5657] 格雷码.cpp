#include <stdio.h>
#include <algorithm>

unsigned long long n, k;

int main()
{
    scanf("%llu%llu", &n, &k);
    k ^= k >> 1;
    while (~--n)
        printf("%llu", (k >> n & 1));
    return 0;
}