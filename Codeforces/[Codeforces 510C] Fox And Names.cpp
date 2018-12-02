#include <stdio.h>
#include <string.h>
#include <queue>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e4;
const int M = 2e4;

int n;
int num_edge, num_ans;
int head[N + 5], ind[N + 5];
char str[N + 5][N + 5], ans[N + 5];
std::queue<int> q;

struct Node
{
    int next, to;
} edge[M + 5];

inline void add_edge(int u, int v)
{
    num_edge++;
    edge[num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
    ind[v]++;
}

void topo_sort()
{
    Rep(i, 1, 26)
    {
        if (!ind[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans[++num_ans] = u + 'a' - 1;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            ind[v]--;
            if (!ind[v])
                q.push(v);
        }
    }
}

int main()
{
    scanf("%d\n", &n);
    Rep(i, 1, n)
        scanf("%s", str[i] + 1);
    Rep(i, 1, n)
        Rep(j, i + 1, n)
        {
            int len_a = strlen(str[i] + 1);
            int len_b = strlen(str[j] + 1);
            Rep(k, 1, len_a)
            {
                if (k > len_b)
                {
                    printf("Impossible");
                    return 0;
                }
                else if (str[i][k] != str[j][k])
                {
                    add_edge(str[i][k] - 'a' + 1, str[j][k] - 'a' + 1);
                    break;
                }
            }
        }
    topo_sort();
    Rep(i, 1, 26)
    {
        if (ind[i])
        {
            printf("Impossible");
            return 0;
        }
    }
    Rep(i, 1, num_ans)
        printf("%c", ans[i]);
    return 0;
}