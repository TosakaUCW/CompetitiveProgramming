#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, ans;

struct Node
{
    int val, pos;
} a[N];

bool cmp(Node a, Node b)
{
    return a.val < b.val;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].val), a[i].pos = i;
    std::sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        if ((a[i].pos - i) % 2)
            ans++;
    printf("%d", ans / 2);
    return 0;
}