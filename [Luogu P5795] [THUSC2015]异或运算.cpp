#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int N = 3e5 + 5;

int n, m, X[N], Y[N];
int t[N][2], ch[N * 35][2], sum[N * 35];
int tot, rt[N];

int insert(int pre, int val)
{
	int p = ++tot, res = p;
	for (int i = 31; ~i; i--)
	{
		int x = (val >> i) & 1;
		ch[p][x ^ 1] = ch[pre][x ^ 1];
		pre = ch[pre][x];
		p = ch[p][x] = ++tot;
		sum[p] = sum[pre] + 1;
	}
	return res;
}

int solve(int x1, int x2, int y1, int y2, int k)
{
	k = (x2 - x1 + 1) * (y2 - y1 + 1) - k + 1;
	for (int i = x1; i <= x2; i++)
		t[i][0] = rt[y1 - 1], t[i][1] = rt[y2];
	int res = 0;
	for (int s = 31; ~s; s--)
	{
		int cnt = 0;
		for (int i = x1, x; i <= x2; i++)
			x = (X[i] >> s) & 1, 
			cnt += sum[ch[t[i][1]][x]] - sum[ch[t[i][0]][x]];
		int nxt = k > cnt;
		if (nxt) k -= cnt;
		res = (res << 1) | nxt;
		for (int i = x1, x; i <= x2; i++)
			x = ((X[i] >> s) & 1) ^ nxt,
			t[i][0] = ch[t[i][0]][x],
			t[i][1] = ch[t[i][1]][x];
	}
	return res;
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) 
		X[i] = read();
	for (int i = 1; i <= m; i++) 
		Y[i] = read(), rt[i] = insert(rt[i - 1], Y[i]);
	for (int q = read(), x1, x2, y1, y2; q--; )
		x1 = read(), x2 = read(), y1 = read(), y2 = read(),
		printf("%d\n", solve(x1, x2, y1, y2, read()));
	return 0;
}