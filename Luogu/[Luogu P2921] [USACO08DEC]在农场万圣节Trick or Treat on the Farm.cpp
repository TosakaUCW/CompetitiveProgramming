#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e5;

int n;
int ans[N + 5], ind[N + 5], next[N + 5];
bool vis[N + 5];

void delete_chain(int u)
{
    vis[u] = true;
    int v = next[u];
    ind[v]--;
    if (!ind[v])
        delete_chain(v);
}

int calc_circle(int u, int depth)
{
    ans[u] = depth;
    int v = next[u];
    if (ans[v])
        return depth;
    else
        return ans[u] = calc_circle(v, depth + 1);
}

int calc(int u)
{
    int v = next[u];
    if (ans[u])
        return ans[u];
    else
        return ans[u] = calc(v) + 1;
}

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
    {
        scanf("%d", &next[i]);
        ind[next[i]]++;
    }
    Rep(i, 1, n)
    {
        if (!ind[i] and !vis[i])
            delete_chain(i);
    }
    Rep(i, 1, n)
    {
        if (ind[i] and !ans[i])
            calc_circle(i, 1);
    }
    Rep(i, 1, n)
    {
        if (!ind[i] and !ans[i])
            calc(i);
    }
    Rep(i, 1, n)
        printf("%d\n", ans[i]);
    return 0;
}