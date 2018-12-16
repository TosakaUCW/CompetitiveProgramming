#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 3e6;

int n, p, inv[N + 5];

int main()
{
    scanf("%d%d", &n, &p);
    inv[1] = 1;
    printf("%d\n", inv[1]);
    Rep(i, 2, n)
    {
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
        printf("%d\n", inv[i]);
    }
    return 0;
}