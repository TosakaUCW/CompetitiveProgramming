#include <stdio.h>
#include <algorithm>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e4 + 5;

int n;
int dfn[N], idx[N], fa[N];
std::vector<int> g[N];

void dfs(int u, int fa)
{
    ::fa[u] = fa, dfn[u] = ++dfn[0], idx[dfn[u]] = u;
    for (int v : g[u]) if (v ^ fa) dfs(v, u);
}

int query(int l, int r)
{
    printf("? %d", r - l + 1);
    for (int i = l; i <= r; i++) printf(" %d", idx[i]);
    printf("\n"), fflush(stdout);
    return read();
}

int main()
{
    int all, ans, l = 1, r = n = read();
    for (int i = 1, u, v; i < n; i++) 
        u = read(), v = read(), 
        g[u].push_back(v), g[v].push_back(u);

    dfs(1, 0);
    all = query(1, n);

    while (l <= r)
    {
        int mid = l + r >> 1;
        int res = mid == 1 ? -1 : query(1, mid);
        if (res == all) r = mid - 1, ans = idx[mid];
        else l = mid + 1;
    }
    printf("! %d %d", ans, fa[ans]);
	return 0;
}
