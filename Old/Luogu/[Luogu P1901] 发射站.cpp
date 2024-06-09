#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e6 + 5;

int n, ans;
int h[N], v[N], a[N];
std::stack<int> s;

int main()
{
	freopen("station.in", "r", stdin);
	freopen("station.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++) h[i] = read(), v[i] = read();
	for (int i = 1; i <= n; i++)
	{
		while (!s.empty() and h[s.top()] < h[i]) a[i] += v[s.top()], s.pop();
		if (!s.empty()) a[s.top()] += v[i];
		s.push(i);
	}
	for (int i = 1; i <= n; i++) ans = std::max(ans, a[i]);
	printf("%d", ans);
	return 0;
}
/*
3
4 2
3 5
6 10
*/
