#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e3;

int n;
int f[N + 5];

int main()
{
    scanf("%d", &n);
    f[1] = 1;
    Rep(i, 2, n)
        f[i] = ((i + 1) & 1) * f[i >> 1] + f[i - 1];
    printf("%d", f[n]);
    return 0;
}