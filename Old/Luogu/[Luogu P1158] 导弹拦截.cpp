#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;
const int INF = 2147483647;

int n, ans = INF;
int max_B;

struct Node
{
    int x, y;
    int dis_A, dis_B;
} A, B, a[N];

int dis(Node A, Node B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }

int cmp(Node a, Node b) { return a.dis_A < b.dis_A; }

int main()
{
    scanf("%d%d%d%d", &A.x, &A.y, &B.x, &B.y);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].dis_A = dis(A, a[i]);
        a[i].dis_B = dis(B, a[i]);
    }
    std::sort(a + 1, a + 1 + n, cmp);
    // max_B = a[n].dis_B;
    for (int i = n; i; i--)
    {
        ans = std::min(ans, a[i].dis_A + max_B);
        max_B = std::max(max_B, a[i].dis_B);
    }
    printf("%d", ans);
    return 0;
}