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

const int N = 1e5 + 5;

int n;
int a[N], b[N], c[N];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	for (int i = 1; i <= n; i++) c[i] = a[i] - b[i];
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += c[i];
	if (sum) return puts("-1"), void();
	std::vector<int> x, y;
	#define pb push_back
	for (int i = 1; i <= n; i++)
		if (c[i] > 0)
			for (int j = 1; j <= c[i]; j++)
				x.pb(i);
		else
			for (int j = 1; j <= -c[i]; j++)
				y.pb(i);
   	printf("%d\n", x.size());
	for (int i = 0; i < x.size(); i++)
		printf("%d %d\n", x[i], y[i]);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

