// luogu-judger-enable-o2
#include <math.h>
#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 5e3;

int n;
double ans, dis[N + 5];
bool vis[N + 5];

struct Node
{
    int x, y;
} point[N + 5];

double distance(int a, int b)
{
    int x = point[a].x - point[b].x;
    int y = point[a].y - point[b].y;
    return sqrt((double)x * x + (double)y * y);
}

void Prim()
{
    int pos = 0;
    dis[1] = 0;
    Rep(i, 1, n)
    {
        double min = 1e9;
        Rep(j, 1, n)
        {
            if (!vis[j] and dis[j] < min)
            {
                min = dis[j];
                pos = j;
            }
        }
        ans += min;
        vis[pos] = true;
        Rep(j, 1, n)
        {
            double dist = distance(pos, j);
            if (dist < dis[j])
                dis[j] = dist;
        }
    }
}

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
    {
        scanf("%d%d", &point[i].x, &point[i].y);
        dis[i] = 1e9;
    }
    Prim();
    printf("%.2f", ans);
    return 0;
}