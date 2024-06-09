#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <map>
#include <queue>

#define output return printf("%d", tot + 1), 0;

const int N = 10 + 5;

std::string ori, tar;
int max, min;

struct Node
{
    std::string str;
    int tot, p;
};

std::queue<Node> Q;
bool vis[6][10][10][10][10][10][10];

#define hash(p, x) (vis[p][x[0] - '0'][x[1] - '0'][x[2] - '0'][x[3] - '0'][x[4] - '0'][x[5] - '0'])

int main()
{
    // freopen("typer.in", "r", stdin);
    // freopen("typer.out", "w", stdout);
    for (int i = 0; i <= 5; i++)
        ori += getchar();
    getchar();
    for (int i = 0; i <= 5; i++)
        tar += getchar();
    max = min = tar[0] - '0';
    for (int i = 1; i <= 5; i++)
        max = std::max(max, tar[i] - '0'), min = std::min(min, tar[i] - '0');
    Q.push(Node{ori, 0, 0}), hash(0, ori) = true;
    for (; !Q.empty();)
    {
        std::string str = Q.front().str, drc;
        int tot = Q.front().tot, p = Q.front().p;
        Q.pop();
        if (str == tar)
            return printf("%d", tot), 0;
        // opt 1 swap(str[p], str[0])
        if (p != 0)
        {
            drc = str;
            std::swap(drc[p], drc[0]);
            if (drc == tar)
                output;
            if (!hash(p, drc))
                hash(p, drc) = true, Q.push(Node{drc, tot + 1, p});
        }
        // opt 2 swap(str[p], str[5])
        if (p != 5)
        {
            drc = str;
            std::swap(drc[p], drc[5]);
            if (drc == tar)
                output;
            if (!hash(p, drc))
                hash(p, drc) = true, Q.push(Node{drc, tot + 1, p});
        }
        // opt 3 inc str[p]
        if (str[p] != '9' and str[p] - '0' != max)
        {
            drc = str;
            drc[p] = drc[p] + 1;
            if (drc == tar)
                output;
            if (!hash(p, drc))
                hash(p, drc) = true, Q.push(Node{drc, tot + 1, p});
        }
        // opt 4 dec str[p]
        if (str[p] != '0' and str[p] - '0' != min)
        {
            drc = str;
            drc[p] = drc[p] - 1;
            if (drc == tar)
                output;
            if (!hash(p, drc))
                hash(p, drc) = true, Q.push(Node{drc, tot + 1, p});
        }
        // opt 5 dec p
        if (p != 0)
            if (!hash(p - 1, str))
                hash(p - 1, str) = true, Q.push(Node{str, tot + 1, p - 1});
        // opt 6 inc p
        if (p != 5)
            if (!hash(p + 1, str))
                hash(p + 1, str) = true, Q.push(Node{str, tot + 1, p + 1});
    }
    return 0;
}