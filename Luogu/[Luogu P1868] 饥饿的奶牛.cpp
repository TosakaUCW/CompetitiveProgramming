#include <stdio.h>
#include <algorithm>
#include <vector>

const int N = 3e6 + 5;

int n, m;
int f[N];

struct Node
{
    int R, val;
    // bool friend operator<(Node a, Node b) { return a.R == b.R ? a.L < b.L : a.R < b.R; }
};

std::vector<Node> V[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int L, R;
        scanf("%d%d", &L, &R);
        V[L].push_back(Node{R, R - L + 1});
        m = std::max(m, R);
    }
    // f[i]=max(f[i-1],f[i-a[i].L]+a[i].val)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < V[i + 1].size(); j++)
        {
            Node x = V[i + 1][j];
            // printf("%d %d\n", i + 1, j);
            f[x.R] = std::max(f[x.R], f[i] + x.val);
            // printf("f[x.R]:%d   f[i] + x.val:%d\n", f[x.R], f[i] + x.val);
        }
        f[i + 1] = std::max(f[i + 1], f[i]);
    }
    printf("%d", f[m]);
    return 0;
}