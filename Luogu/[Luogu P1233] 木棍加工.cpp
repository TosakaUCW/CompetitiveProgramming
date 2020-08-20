#include <stdio.h>
#include <algorithm>

const int N = 5e4 + 5;

int n;
int s[N], len;

struct Node
{
    int l, w;
    bool friend operator<(Node a, Node b) { return a.l == b.l ? a.w > b.w : a.l > b.l; }
} a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].l, &a[i].w);
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].w > s[len])
            s[++len] = a[i].w;
        else
        {
            int L = 1, R = len, res;
            while (L <= R)
            {
                int mid = (L + R) / 2;
                if (s[mid] >= a[i].w)
                    res = mid, R = mid - 1;
                else
                    L = mid + 1;
            }
            s[res] = a[i].w;
        }
    }
    printf("%d", len);
    return 0;
}