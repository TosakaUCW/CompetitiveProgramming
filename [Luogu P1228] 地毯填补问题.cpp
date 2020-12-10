#include <stdio.h>

void search(int a, int b, int x, int y, int n)
{
    if (n == 1)
        return;
    n >>= 1;
    if (x - a < n and y - b < n)
    {
        printf("%d %d %d\n", a + n, b + n, 1);
        search(a, b, x, y, n);
        search(a, b + n, a + n - 1, b + n, n);
        search(a + n, b, a + n, b + n - 1, n);
        search(a + n, b + n, a + n, b + n, n);
    }
    else if (x - a < n and y - b >= n)
    {
        printf("%d %d %d\n", a + n, b + n - 1, 2);
        search(a, b, a + n - 1, b + n - 1, n);
        search(a, b + n, x, y, n);
        search(a + n, b, a + n, b + n - 1, n);
        search(a + n, b + n, a + n, b + n, n);
    }
    else if (x - a >= n and y - b < n)
    {
        printf("%d %d %d\n", a + n - 1, b + n, 3);
        search(a, b, a + n - 1, b + n - 1, n);
        search(a, b + n, a + n - 1, b + n, n);
        search(a + n, b, x, y, n);
        search(a + n, b + n, a + n, b + n, n);
    }
    else
    {
        printf("%d %d %d\n", a + n - 1, b + n - 1, 4);
        search(a, b, a + n - 1, b + n - 1, n);
        search(a, b + n, a + n - 1, b + n, n);
        search(a + n, b, a + n, b + n - 1, n);
        search(a + n, b + n, x, y, n);
    }
}

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    search(1, 1, x, y, 1 << n);
    return 0;
}