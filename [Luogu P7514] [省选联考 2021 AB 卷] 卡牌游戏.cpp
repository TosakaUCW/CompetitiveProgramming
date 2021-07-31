#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e6 + 5;
const int INF = 2147483647;

int n, k;
bool used[N];
struct Node
{
	int val, typ, idx;
	bool friend operator < (Node a, Node b) { return a.val < b.val; }
} a[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("card3.in", "r", stdin);
#endif
	n = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = {read(), 1, i};
	for (int i = 1; i <= n; i++) a[i + n] = {read(), 0, i};
	std::sort(a + 1, a + 1 + 2 * n);
	int L = 0 , R = 2 * n + 1, cnt = 0;
	while (cnt + a[R - 1].typ <= k and !used[a[R - 1].idx]) cnt += a[R - 1].typ, used[a[R - 1].idx] = 1, R--;
	while (cnt + a[L + 1].typ <= k and !used[a[L + 1].idx]) cnt += a[L + 1].typ, used[a[L + 1].idx] = 1, L++;
	int ans = INF;
	while (R <= 2 * n + 1)
	{
		ans = std::min(ans, a[R - 1].val - a[L + 1].val);
		used[a[R].idx] = 0, cnt -= a[R].typ, R++;
		while (cnt + a[L + 1].typ <= k and !used[a[L + 1].idx] and L + 1 <= R) cnt += a[L + 1].typ, used[a[L + 1].idx] = 1, L++;
	}
	return printf("%d", ans), 0;
}

