#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 15e4 + 5;

int n;
int ans, T;

struct Node
{
    int a, t;
    bool friend operator<(Node a, Node b) { return a.t < b.t; }
} a[N];

std::priority_queue<int> Q;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].a, &a[i].t);
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        if (T + a[i].a > a[i].t)
        {
            if (a[i].a < Q.top())
                T -= Q.top(), Q.pop(), Q.push(a[i].a), T += a[i].a;
        }
        else
            Q.push(a[i].a), T += a[i].a, ans++;
    printf("%d", ans);
    return 0;
}