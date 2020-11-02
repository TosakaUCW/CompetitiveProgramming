#include <stdio.h>

int n, m, k;

int main()
{
    scanf("%d%d%*d", &n, &k);
    for (int i = 1, sum = 0, tmp, tmppp; i <= k; i++, printf("%d\n", sum % (n + 1) + 1), sum = 0)
        for (scanf("%d", &m), tmppp = m; tmppp--; sum += tmp)
            scanf("%d", &tmp);
    return 0;
}