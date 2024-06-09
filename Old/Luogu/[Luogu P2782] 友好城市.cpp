#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;

int n;
int f[N], len;
struct Node
{
    int x, y;
    bool friend operator<(Node a, Node b) { return a.y < b.y; }
} a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].x > f[len])
            f[++len] = a[i].x;
        else
        {
            int L = 1, R = len, res;
            while (L <= R)
            {
                int mid = (L + R) / 2;
                if (a[i].x > f[mid])
                    res = mid, L = mid + 1;
                else
                    R = mid - 1;
            }
            f[res + 1] = a[i].x;
        }
    }
    printf("%d", len);
    return 0;
}