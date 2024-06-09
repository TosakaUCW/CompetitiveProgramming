#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <iostream>
#include <string>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e7 + 5;
const int P = 1e9 + 7;

int pow(int x, int k)
{
    int res = 1;
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

int k, n, res, ans;
int E;
std::map<int, int> mp, col, f[7], vis, hd;
struct Node
{
    int ne, to;
} e[N];
void add(int u, int v) { e[++E] = {hd[u], v}, hd[u] = E; }

#define pb emplace_back

void dfs(int x)
{
    if (col.count(x))
        for (int i = 1; i <= 6; i++)
            f[i][x] = i == mp[col[x]];
    else
        for (int i = 1; i <= 6; i++)
            f[i][x] = 1;
    for (int i = hd[x], v = e[i].to; i; i = e[i].ne, v = e[i].to)
    {
        dfs(v);
        for (int i = 1; i <= 6; i++)
        {
            int sum = 0;
            for (int j = 1; j <= 6; j++)
                if (i != j and i + j != 7)
                    sum = (f[j][v] + sum) % P;
            f[i][x] = f[i][x] * sum % P;
        }
    }
}

signed main()
{
    k = read(), n = read(), res = (1LL << k) - 2;
    mp['w'] = 1, mp['y'] = 6, mp['g'] = 2, mp['b'] = 5, mp['r'] = 3, mp['o'] = 4;
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::string s;
        std::cin >> x >> s;
        col[x] = s[0];
        for (int p = x; p > 1 and !vis[p]; p >>= 1)
            vis[p] = 1, res--, add(p / 2, p);
    }
    dfs(1);
    for (int i = 1; i <= 6; i++)
        ans = (ans + f[i][1]) % P;
    printf("%lld", ans * pow(4, res) % P);
    return 0;
}