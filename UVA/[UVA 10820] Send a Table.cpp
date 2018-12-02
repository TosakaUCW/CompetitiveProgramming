#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 6e4;

int n, phi[N + 5];

void sieve()
{
    Rep(i, 1, n)
        phi[i] = 0;
    phi[1] = 1;
    Rep(i, 2, n)
    {
        if (!phi[i])
            for (int j = i; j <= n; j += i)
            {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
    }
}

int main()
{
    while (scanf("%d", &n) and n != 0)
    {
        sieve();
        int ans = 0;
        Rep(i, 2, n)
            ans += phi[i];
        ans = 2 * ans + 1;
        printf("%d\n", ans);
    }
    return 0;
}
