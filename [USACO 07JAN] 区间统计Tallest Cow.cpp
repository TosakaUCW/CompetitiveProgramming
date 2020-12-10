#include <stdio.h>
#include <algorithm>
#include <map>

const int N = 1e4 + 5;

int n, l, h, r;
int d[N];
std::map<std::pair<int, int>, bool> map;

int main()
{
    scanf("%d%d%d%d", &n, &l, &h, &r);
    for (int i = 1; i <= r; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y)
            std::swap(x, y);
        if (map[std::make_pair(x, y)])
            continue;
        map[std::make_pair(x, y)] = true;
        d[x + 1]--, d[y]++;
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] = d[i - 1] + d[i];
        printf("%d\n", h + d[i]);
    }
    return 0;
}