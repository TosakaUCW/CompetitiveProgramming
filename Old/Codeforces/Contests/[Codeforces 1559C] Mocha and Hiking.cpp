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

const int N = 1e4 + 5;

int n, a[N];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	if (a[1]) { printf("%d ", n + 1); for (int i = 1; i <= n; i++) printf("%d ", i); }
	else
	{
		int flag = 0, pos;
		for (int i = 1; i <= n; i++) if (!a[i] and a[i + 1]) { flag = 1, pos = i; break; }
		if (!flag and a[n]) printf("%d", -1);
		else
		{
			if (!flag) pos = n;
			for (int i = 1; i <= pos; i++) printf("%d ",i);
			printf("%d ", n + 1);
			for (int i = pos + 1; i <= n; i++) printf("%d ",i);
		}
	}
}

int main()
{
	for (int T = read(); T--; solve(), puts(""));
	return 0;
}
