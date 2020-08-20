#include <stdio.h>
#include <algorithm>
#include <vector>

const int N = 3.2e4 + 5;
const int M = 2e5 + 5;

int n, m;
int f[M];

struct Node
{
    int wei, val;
};

std::vector<Node> a[N];

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (!z)
            a[i].push_back(Node{x, x * y});
        else
            for (int k = 0, tmp = a[z].size(); k < tmp; k++)
                a[z].push_back(Node{x + a[z][k].wei, x * y + a[z][k].val});
    }
    for (int i = 1; i <= n; i++)
        if (a[i].size())
        {
            for (int j = m; j; j--)
                for (int k = 0; k < a[i].size(); k++)
                    if (j >= a[i][k].wei)
                        f[j] = std::max(f[j], f[j - a[i][k].wei] + a[i][k].val);
        }
    printf("%d", f[m]);
    return 0;
}