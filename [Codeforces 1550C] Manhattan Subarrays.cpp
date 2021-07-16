#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e5 + 5;

int a[N];

bool f(int i, int j, int k)
{
	if (a[i] <= a[j] and a[j] <= a[k]) return false;
	if (a[i] >= a[j] and a[j] >= a[k]) return false;
	return true;
}

void solve()
{
	int n = read(), ans = 0;
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i + 3 - 1 <= n; i++) ans += f(i, i + 1, i + 2);
	for (int i = 1; i + 4 - 1 <= n; i++)
		if (f(i, i + 1, i + 2) and f(i, i + 1, i + 3) and f(i, i + 2, i + 3) and f(i + 1, i + 2, i + 3))
		   ans++;
	printf("%d\n", ans + n + n - 1);  
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

