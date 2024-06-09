#include <stdio.h>

int n, ans;
int a[2];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int x = a[0] = a[1] = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &x), a[i % 2] += (x % 2 != i % 2) ? 1 : 0;
        printf("%d\n", a[0] != a[1] ? -1 : a[0]);
    }
    return 0;
}