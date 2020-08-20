#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;
const int P = 1e8 - 3;

int n;
int c[N], d[N];

struct Node
{
    int val = 0, pos = 0;
    bool friend operator<(Node a, Node b) { return a.val < b.val; };
} a[N], b[N];

int go(int l, int r)
{

    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    int res = (go(l, mid) + go(mid + 1, r)) % P;
    int i = l, j = mid + 1, k = l;
    while (i <= mid and j <= r)
        if (c[i] <= c[j])
            d[k++] = c[i++];
        else
            d[k++] = c[j++], (res += mid - i + 1) %= P;
    while (i <= mid)
        d[k++] = c[i++];
    while (j <= r)
        d[k++] = c[j++];
    for (int i = l; i <= r; i++)
        c[i] = d[i];
    return res % P;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].val), a[i].pos = i;
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i].val), b[i].pos = i;
    std::sort(a + 1, a + 1 + n), std::sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
        c[a[i].pos] = b[i].pos;
    printf("%d", go(1, n));
    return 0;
}