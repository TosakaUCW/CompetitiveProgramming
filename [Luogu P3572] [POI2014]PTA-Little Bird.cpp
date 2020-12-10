#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e6 + 5;

int n, m;
int a[N];
int f[N];
int Q[N], head, tail;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    while (m--)
    {
        int k;
        scanf("%d", &k);
        head = tail = 1;
        Q[tail] = 1;
        for (int i = 2; i <= n; i++)
        {
            while (head <= tail and i - Q[head] > k)
                head++;
            if (a[Q[head]] > a[i])
                f[i] = f[Q[head]];
            else
                f[i] = f[Q[head]] + 1;
            while (head <= tail and (f[Q[tail]] > f[i] or (f[Q[tail]] == f[i] and a[Q[tail]] <= a[i])))
                tail--;
            Q[++tail] = i;
        }
        printf("%d\n", f[n]);
    }
    return 0;
}