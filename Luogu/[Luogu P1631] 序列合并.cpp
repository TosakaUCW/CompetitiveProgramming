#include <stdio.h>
#include <algorithm>
#include <queue>
#include <memory.h>

const int N = 1e5 + 5;

int n;
int a[N], b[N];
struct Node
{
    int val, x, y;
    bool friend operator<(Node a, Node b) { return a.val > b.val; }
};
std::priority_queue<Node> Q;
int ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    // std::sort(a + 1, a + 1 + n);
    // std::sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
        Q.push(Node{a[i] + b[1], i, 1});
    while (n--)
    {
        int val = Q.top().val;
        int x = Q.top().x;
        int y = Q.top().y;
        Q.pop();
        printf("%d ", val);
        Q.push(Node{a[x] + b[y + 1], x, y + 1});
    }
    return 0;
}