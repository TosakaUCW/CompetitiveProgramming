#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e6 + 5;

int n, m1, m2, fa1[N], fa2[N];
std::vector< std::pair<int, int> > ans;
std::vector<int> a, b;
#define pb push_back

int find1(int x) { return x == fa1[x] ? x : fa1[x] = find1(fa1[x]); }
int find2(int x) { return x == fa2[x] ? x : fa2[x] = find2(fa2[x]); }
void merge1(int x, int y) { fa1[find1(x)] = find1(y); }
void merge2(int x, int y) { fa2[find2(x)] = find2(y); }

int main()
{
	n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= n; i++) fa1[i] = fa2[i] = i;
	for (int x, y; m1--; ) x = read(), y = read(), merge1(x, y);
	for (int x, y; m2--; ) x = read(), y = read(), merge2(x, y);
	for (int i = 2; i <= n; i++)
		if (find1(1) != find1(i) and find2(1) != find2(i)) merge1(1, i), merge2(1, i), ans.pb({1, i});
	for (int i = 2; i <= n; i++)
	{
		if (find1(1) != find1(i)) merge1(1, i), a.pb(i);
		else if (find2(1) != find2(i)) merge2(1, i), b.pb(i);
	}
	printf("%d\n", ans.size() + std::min(a.size(), b.size()));
	for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
	for (int i = 0; i < std::min(a.size(), b.size()); i++) printf("%d %d\n", a[i], b[i]);
	return 0;
}
