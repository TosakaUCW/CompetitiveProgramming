#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e5 + 5;

int n, m;
int num_node;
char str[N];
int trie[N][2], cnt[N], tot[N];

void insert(char *str, int len)
{
    int u = 0;
    for (int i = 0; i < len; i++)
    {
        int c = str[i];
        if (!trie[u][c])
            trie[u][c] = ++num_node;
        u = trie[u][c];
        tot[u]++;
    }
    cnt[u]++;
}

int find(char *str, int len)
{
    int u = 0, res = 0;
    for (int i = 0; i < len; i++)
    {
        int c = str[i];
        if (!trie[u][c])
            return res;
        u = trie[u][c];
        res += cnt[u];
    }
    return res - cnt[u] + tot[u];
}

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int main()
{
    m = read(), n = read();
    while (m--)
    {
        int len = read();
        for (int j = 0, x; j < len; j++)
            x = read(), str[j] = x;
        insert(str, len);
    }
    while (n--)
    {
        int len = read();
        for (int j = 0, x; j < len; j++)
            x = read(), str[j] = x;
        printf("%d\n", find(str, len));
    }
    return 0;
}