#include <algorithm>
#include <stdio.h>

const int N = 1e3 + 5;

int n;
int wei[N], val[N], f[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        wei[i] = i;
        for (int k = 1; k < i; k++)
            if (i % k == 0)
                val[i] += k;
    }
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= wei[i]; j--)
            f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
    printf("%d", f[n]);
    return 0;
}