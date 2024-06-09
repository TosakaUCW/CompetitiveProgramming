#include <stdio.h>
#include <algorithm>
#include <vector>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e5 + 5;

int n;
int b[N], c[N];
std::vector<int> a[N]; 

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) b[i] = read(), a[i].clear(), c[i] = 0;
	for (int i = 1; i <= n; i++) a[b[i]].push_back(read());
	for (int i = 1; i <= n; i++) 
		if (a[i].size())
		{
			std::sort(a[i].rbegin(), a[i].rend());
			for (int j = 1; j < a[i].size(); j++) 
				a[i][j] += a[i][j - 1];
		}
	for (int i = 1; i <= n; i++)
		if (a[i].size())
		{
			for (int j = 1; j <= a[i].size(); j++)
				c[j] += a[i][a[i].size() / j * j - 1];
		}
	for (int i = 1; i <= n; i++) printf("%lld ", c[i]);
	puts("");
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}
