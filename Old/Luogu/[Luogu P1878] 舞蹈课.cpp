#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <iostream>

#define judge

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e6 + 5;

int n;
bool b[N];

struct Node
{
	int sex, pre, nex, val;
} a[N];
struct node 
{ 
	int val, a, b; 
	bool friend operator<(node a, node b) { return a.val ^ b.val ? a.val > b.val : a.a > b.a;	}
};

std::priority_queue<node> Q;
std::vector<std::pair<int, int>> V;

int main()
{
#ifndef judge
	freopen("dancinglessons.in", "r", stdin),
	freopen("dancinglessons.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; i++)
	{
		char ch; std::cin >> ch;
		a[i].sex = ch == 'B';
	}

	for (int i = 1; i <= n; i++) 
		a[i].val = read(), a[i].pre = i - 1, a[i].nex = i + 1;

	for (int i = 1; i < n; i++)
		if (a[i].sex ^ a[i + 1].sex)
            Q.push(node{  abs(a[i].val - a[i + 1].val), i, i + 1 });

	for (; !Q.empty(); )
	{
		node x = Q.top(); Q.pop();
        if (b[x.a] or b[x.b]) continue;
		V.push_back({x.a, x.b});
        b[x.a] = b[x.b] = 1;
        
		int p = a[x.a].pre, q = a[x.b].nex;

        a[p].nex = q, a[q].pre = p;
        if (p != 0 and q != n + 1 and a[p].sex ^ a[q].sex)
            Q.push(node { abs(a[p].val - a[q].val), p, q });

	}
	printf("%d\n", (int)V.size());
	for (auto x : V) printf("%d %d\n", x.first, x.second);
	return 0;
}
