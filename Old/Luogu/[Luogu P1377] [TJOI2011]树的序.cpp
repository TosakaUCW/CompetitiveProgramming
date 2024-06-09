#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;

int stk[N], top, a[N], ls[N], rs[N], n;

void print(int u) { if(u) printf("%d ", u), print(ls[u]), print(rs[u]); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
#endif
	n = read();
	for (int i = 1; i <= n; i++) a[read()] = i;
	for (int i = 1; i <= n; i++)
	{
		int k = top;
		while (k and a[stk[k]] > a[i]) k--;
		if (k) rs[stk[k]] = i;
		if (k < top) ls[i] = stk[k + 1];
		stk[++k] = i, top = k;
	}
	return print(stk[1]), 0;
}
