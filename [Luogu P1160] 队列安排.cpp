#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>
#include <queue>

const int N = 1e5 + 5;

int n, m;
int a[N];
int find[N];

struct Node
{
    int val, prev, next;
} node[N];
int head, tail, tot;

void init()
{
    head = 1, tail = tot = 2;
    node[head].next = tail;
    node[tail].prev = head;
    find[head] = 1, find[tail] = 2;
}

void insert(int p, int val)
{
    int q = ++tot;
    node[q].val = val;
    node[node[p].next].prev = q;
    node[q].next = node[p].next;
    node[p].next = q;
    node[q].prev = p;
    find[val] = q;
}

void remove(int p, int val)
{
    node[node[p].prev].next = node[p].next;
    node[node[p].next].prev = node[p].prev;
    find[val] = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("P1160_2.in", "r", stdin);
    freopen("P1160_2.ans", "w", stdout);
#endif // !ONLINE_JUDGE
    scanf("%d", &n);
    init();
    insert(head, 1);
    for (int i = 2; i <= n; i++)
    {
        int opt, k;
        scanf("%d%d", &k, &opt);
        // puts("1");
        // int p = head;
        // while (node[p].val != k and node[p].next != tail)
        // p = node[p].next;
        if (opt == 0) //i->k
            insert(node[find[k]].prev, i);
        else //k->i
            insert(find[k], i);
        // printf("%d %d\n", node[p].val, k);
    }
    scanf("%d", &m);
    while (m--)
    {
        int k;
        scanf("%d", &k);
        // puts("1");
        // int p = head;
        // while (p != tail and node[p].val != k)
        //     p = node[p].next;
        if (find[k] != 0)
            remove(find[k], k);
    }
    int p = node[head].next;
    while (p != tail)
        printf("%d ", node[p].val), p = node[p].next;
    return 0;
}