#include <stdio.h>
#include <algorithm>
#include <queue>

const int N = 1e5 + 5;

int n;
bool inQ1[N];
int max_ans, max_pos, max_idx;

struct Node1
{
    int val, pos, idx;
    bool friend operator<(Node1 A, Node1 B) { return A.val < B.val; }
} a[N];

struct Node2
{
    int val, pos, idx;
    bool friend operator<(Node2 A, Node2 B) { return A.val + A.pos * 2 > B.val + B.pos * 2; }
};

bool cmp(Node1 a, Node1 b) { return a.pos < b.pos; }

std::priority_queue<Node1> Q1;
std::priority_queue<Node2> Q2;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].pos);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].val), a[i].idx = i;
    std::sort(a + 1, a + 1 + n, cmp);
    // int max_ans = 0, max_pos;
    for (int i = 1; i <= n; i++)
        if (a[i].val + 2 * a[i].pos > max_ans)
            max_ans = a[i].val + 2 * a[i].pos, max_pos = a[i].pos, max_idx = a[i].idx;
    for (int i = 1; i <= n; i++)
        if (a[i].idx == max_idx)
            continue;
        else if (a[i].pos <= max_pos)
            Q1.push(Node1{a[i].val, a[i].pos, a[i].idx}), inQ1[a[i].idx] = true;
        else
            Q2.push(Node2{a[i].val, a[i].pos, a[i].idx});

    /*
    printf("%d\n", max_pos);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i].pos);
    while (!Q1.empty())
        printf("Q1: %d\n ", Q1.top().val), Q1.pop();
    puts("");
    while (!Q2.empty())
        printf("Q2: %d \n", Q2.top().val), Q2.pop();
        */

    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", max_ans);
        while (!Q2.empty() and inQ1[Q2.top().idx])
            Q1.push(Node1{Q2.top().val, Q2.top().pos, Q2.top().idx}), Q2.pop();

        if (Q2.empty())
            max_ans += Q1.top().val, Q1.pop();
        else if (Q1.empty())
        {
            int k = Q2.top().val + 2 * (Q2.top().pos - max_pos);
            max_ans += k;
            for (int i = max_pos + 1; i <= Q2.top().pos; i++)
                inQ1[i] = true;
        }
        else if (Q1.top().val > Q2.top().val + 2 * (Q2.top().pos - max_pos))
        {
#ifndef ONLINE_JUDGE
            // printf("Q.top().val %d", Q1.top().val);
#endif // !ONLINE_JUDGE
            max_ans += Q1.top().val, Q1.pop();
        }

        else if (Q1.top().val <= Q2.top().val + 2 * (Q2.top().pos - max_pos))
        {
            int k = Q2.top().val + 2 * (Q2.top().pos - max_pos);
            max_ans += k;
            max_idx = Q2.top().idx;
#ifndef ONLINE_JUDGE
            // printf("Q.top().val:%d\n", Q1.top().val);
            // printf("k: %d\n", k);
#endif // !ONLINE_JUDG
            for (int i = max_idx; i <= Q2.top().idx; i++)
                inQ1[i] = true;
            Q2.pop();
        }
    }
    return 0;
}