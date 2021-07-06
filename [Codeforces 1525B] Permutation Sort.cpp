#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 50 + 5;

int n, a[N];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	bool flag = true;
	for (int i = 1; i <= n and flag; i++)
		flag &= (a[i] == a[i - 1] + 1);
	if (flag) puts("0");
	else if (a[1] == 1 or a[n] == n) puts("1");
	else if (a[n] == 1 and a[1] == n) puts("3"); 
	else puts("2");
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
