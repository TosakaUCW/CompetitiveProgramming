#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <string.h>
#include <stdlib.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2e3 + 5;
const int M = 1e6 + 5;

int n;
char str[N][N], ans[26];
int num_edge, head[N], ind[26];
int trie[N * N + 5][26], node_cnt;
std::queue<int> Q;

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

void insert(int x)
{
    int p = 0;
    for (int i = 1, m = strlen(str[x] + 1), t; i <= m; i++)
    {
        t = str[x][i] - 'a';
        if (!trie[p][t])
            trie[p][t] = ++node_cnt;
        for (int k = 0; k < 26; k++)
            if (k != t and trie[p][k])
                add_edge(k, t), ind[t]++;
        p = trie[p][t];
    }
    for (int k = 0; k < 26; k++)
        if (trie[p][k])
            puts("NE"), exit(0);
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", str[i] + 1);
    for (int i = 1; i <= n; i++)
        insert(read());
    for (int i = 0; i < 26; i++)
        if (!ind[i])
            Q.push(i);
    for (int u, i = 0; !Q.empty(); i++)
    {
        u = Q.front(), Q.pop(), ans[u] = 'a' + i;
        for (int i = head[u], v; i; i = edge[i].next)
            if (!(--ind[v = edge[i].to]))
                Q.push(v);
    }
    for (int i = 0; i < 26; i++)
        if (ind[i])
            return puts("NE"), 0;
    return printf("DA\n%s", ans), 0;
}