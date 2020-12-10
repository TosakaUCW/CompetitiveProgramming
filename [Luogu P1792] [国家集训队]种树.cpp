#include <stdio.h>
#include <algorithm>
#include <queue>

const int N = 4e5 + 5;

int n, m, ans;
int L[N], R[N];
bool vis[N];
struct Node
{
    int val, idx;
    bool friend operator<(Node a, Node b) { return a.val < b.val; }
} a[N];

std::priority_queue<Node> Q;

int get()
{
    while (1)
    {
        Node top = Q.top();
        Q.pop();
        if (!vis[top.idx])
            return top.idx;
    }
}

void del(int x) { R[L[x]] = R[x], L[R[x]] = L[x], vis[x] = true; }

int main()
{
    scanf("%d%d", &n, &m);
    if (2 * m > n)
    {
        puts("Error!");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].val), a[i].idx = i, Q.push(a[i]);
    for (int i = 1; i <= n; i++)
        L[i] = i - 1, R[i] = i + 1;
    L[1] = n, R[n] = 1;
    while (m--)
    {
        int x = get();
        ans += a[x].val;
        // printf("%d\n", a[x].val);
        a[x].val = a[L[x]].val + a[R[x]].val - a[x].val;
        Q.push({a[x]});
        del(L[x]), del(R[x]);
    }
    printf("%d", ans);
    return 0;
}