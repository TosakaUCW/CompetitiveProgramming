#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e4 + 5;

int n, m, ans;
int a[N], b[N], c[N];

struct Node
{
    int val, x, i;
    bool friend operator<(Node A, Node B) { return A.val > B.val; }
};

std::priority_queue<Node> Q;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i], &b[i], &c[i]), Q.push(Node{a[i] + b[i] + c[i], 1, i});
    while (m--)
    {
        printf("%d ", Q.top().val);
        int x = Q.top().x + 1;
        int i = Q.top().i;
        Q.pop();
        int val = x * x * a[i] + x * b[i] + c[i];
        Q.push(Node{val, x, i});
    }
    // printf("%d", ans);
    return 0;
}