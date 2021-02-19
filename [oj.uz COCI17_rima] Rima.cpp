#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int M = 3e6 + 5;

int n, nodecnt, ans;
int trie[M][30], sum[M], f[M];
bool tag[M];
char s[M];
std::pair<int, int> max[M];

void insert(char *s)
{
    int len = strlen(s + 1), p = 0;
    for (int i = len; i >= 1; i--)
    {
        if (!trie[p][s[i] - 'a'])
            trie[p][s[i] - 'a'] = ++nodecnt;
        p = trie[p][s[i] - 'a'];
    }
    tag[p] = true;
}

void dfs(int u)
{
    for (int i = 0, v; i < 26; i++)
        if (v = trie[u][i])
        {
            dfs(v);
            if (tag[v])
                sum[u]++;
            f[u] = std::max(f[u], f[v]);
            if (f[v] > max[u].first)
                max[u].second = max[u].first, max[u].first = f[v];
            else if (f[v] > max[u].second)
                max[u].second = f[v];
        }
    if (tag[u])
        f[u] += std::max(1, sum[u]);
    else
        f[u] = 0;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", s + 1), insert(s);
    dfs(0);
    for (int i = 0; i < nodecnt; i++)
        ans = std::max(ans, max[i].first + max[i].second + tag[i] + std::max(0, sum[i] - 2));
    return printf("%d", ans), 0;
}