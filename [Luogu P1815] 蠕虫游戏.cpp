#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>

const int N = 1e5 + 5;
const int dx[] = {0, -1, +1, 0, 0};
const int dy[] = {0, 0, 0, +1, -1};

int n, head, nodecnt, tail;
std::string str;
int flag;

struct Node
{
    int x, y, pre;
} ywb[N];

int read()
{
    int f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while (ch >= '0' and ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void init()
{
    nodecnt = 0, head = 0, tail = 0;
    memset(ywb, 0, sizeof ywb);
    for (int i = 30; i >= 11; i--)
        ++nodecnt, ywb[nodecnt].pre = nodecnt - 1, ywb[nodecnt].x = 25, ywb[nodecnt].y = i;
    ywb[1].pre = -1;
    head = 1, tail = nodecnt;
}

int move(int opt)
{
    int x = ywb[head].x, y = ywb[head].y;
    int xx = x + dx[opt], yy = y + dy[opt];
    if (xx < 1 or xx > 50 or yy < 1 or yy > 50)
        return 1;
    Node p = ywb[ywb[tail].pre];
    while (1)
    {
        if (xx == p.x and yy == p.y)
            return 0;
        if (p.pre == -1)
            break;
        p = ywb[p.pre];
    }
    tail = ywb[tail].pre;
    ++nodecnt;
    ywb[head].pre = nodecnt;
    head = nodecnt;
    ywb[head].x = xx, ywb[head].y = yy;
    ywb[head].pre = -1;
    return -1;
}

void solve()
{
    flag = -1;
    std::cin >> str;
    init();
    for (int i = 0; i < n and flag == -1; i++)
    {
        if (str[i] == 'N')
            flag = move(1);
        else if (str[i] == 'S')
            flag = move(2);
        else if (str[i] == 'E')
            flag = move(3);
        else
            flag = move(4);
        if (flag == 0)
            printf("The worm ran into itself on move %d.\n", i + 1);
        else if (flag == 1)
            printf("The worm ran off the board on move %d.\n", i + 1);
    }
    if (flag == -1)
        printf("The worm successfully made all %d moves.\n", n);
}

int main()
{
    // freopen("WORM.in", "r", stdin), freopen("WORM.out", "w", stdout);
    for (n = read(); n != 0; n = read())
        solve();
    return 0;
}
