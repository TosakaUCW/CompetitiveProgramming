#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 3e5 + 5;

int n, ans;
int a[N], b[N], f[N];
std::set<int> S;
std::queue<int> Q;
std::pair<int, int> g[N];

#define fi first
#define se second
#define ins insert
#define pb emplace_back

void print(int x)
{
    if (g[x].fi == -1)
        return printf("%d\n", ans), void();
    else
        ans++, print(g[x].se);
    printf("%d ", g[x].fi);
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = i - read();
    for (int i = 1; i <= n; i++)
        b[i] = i + read();
    for (int i = 0; i <= n; i++)
        S.ins(i), f[i] = -1;
    f[n] = 0, Q.push(n), g[n] = {-1, -1};
    for (int u; !Q.empty();)
    {
        u = Q.front(), Q.pop();
        while (1)
        {
            auto it = S.lower_bound(a[u]);
            int v = *it;
            if (it == S.end() or v > u)
                break;
            if (f[b[v]] == -1)
                f[b[v]] = f[u] + 1, g[b[v]] = {v, u}, Q.push(b[v]);
            S.erase(it);
        }
    }
    if (f[0] == -1)
        puts("-1");
    else
        print(0);
}

int main() { return solve(), 0; }