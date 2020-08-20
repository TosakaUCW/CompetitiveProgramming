#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, d;
int max_head = 1, max_tail = 0;
int min_head = 1, min_tail = 0;

struct Node
{
    int x, y;
    bool friend operator<(Node a, Node b) { return a.x < b.x; }
} point[N], Q_max[N], Q_min[N];

bool judge(int len)
{
    int res = 0;
    max_head = 1, max_tail = 0;
    min_head = 1, min_tail = 0;
    for (int i = 1; i <= n; i++)
    {
        while (max_head <= max_tail and Q_max[max_head].x + len < point[i].x)
            max_head++;
        while (min_head <= min_tail and Q_min[min_head].x + len < point[i].x)
            min_head++;

        while (max_head <= max_tail and Q_max[max_tail].y <= point[i].y)
            max_tail--;
        while (min_head <= min_tail and Q_min[min_tail].y >= point[i].y)
            min_tail--;
        Q_max[++max_tail] = point[i];
        Q_min[++min_tail] = point[i];
        res = std::max(res, Q_max[max_head].y - Q_min[min_head].y);
    }
    return res >= d;
}

int main()
{
    int L = 1, R = 1e6 + 5, ans = -1;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &point[i].x, &point[i].y);
    std::sort(point + 1, point + 1 + n);
    // for (int i = 1; i <= n; i++)
    // printf("%d %d\n", point[i].x, point[i].y);
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    printf("%d", ans);
    return 0;
}