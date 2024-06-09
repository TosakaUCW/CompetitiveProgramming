#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

#define int long long

const int N = 1e5 + 5;
const int M = 65;

int n, ans[N];
std::queue<int> Q[M];

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while ('0' > ch or ch > '9')
		f = ch == '-' ? -1 : 1, ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

signed main()
{
	n = read();
	for (int i = 1, x; i <= n; i++)
	{
		x = read();
		for (int j = 60, flag = 1; j >= 0 and flag; j--)
			if (x & (1 << j))
				Q[j].push(x), flag = 0;
	}
	for (int i = 1, flag = 1, x = 0; i <= n; i++, flag = 1)
	{
		for (int j = 0; j <= 60 and flag; j++)
			if (!(x & (1LL << j)) and !Q[j].empty())
				x ^= (ans[i] = Q[j].front()), Q[j].pop(), flag = 0;
		if (flag)
			return puts("No"), 0;
	}
	puts("Yes");
	for (int i = 1; i <= n; i++)
		printf("%I64d ", ans[i]);
	return 0;
}