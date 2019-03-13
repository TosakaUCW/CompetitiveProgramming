#include <stdio.h>

const int N = 1e6 + 5;

int n, k, a[N], queue[3 * N];

void min()
{
    int head = 1, tail = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head <= tail and queue[head] + k <= i)
            ++head;
        while (head <= tail and a[queue[tail]] > a[i])
            --tail;
        queue[++tail] = i;
        if (i >= k)
            printf("%d ", a[queue[head]]);
    }
}

void max()
{
    int head = 1, tail = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head <= tail and queue[head] + k <= i)
            ++head;
        while (head <= tail and a[queue[tail]] < a[i])
            --tail;
        queue[++tail] = i;
        if (i >= k)
            printf("%d ", a[queue[head]]);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    min();
    printf("\n");
    max();
    return 0;
}