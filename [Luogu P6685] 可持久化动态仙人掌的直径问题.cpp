#include <stdio.h>
#include <algorithm>
#include <math.h>

int n, m, ans;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        if (pow(i, m) <= n)
            ans++;
        else
            break;
    printf("%d", ans);
    return 0;
}