#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

#define flush fflush(stdout)

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < '0' or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 100 + 5;

int n;
bool ans[N][N];
std::vector<int> path;

bool many_edge(int x, int len)
{
	if (len < 0) return false;
	printf("2 %d %d ", x, len + 1);
	for (int i = 0; i <= len; i++)
		printf("%d ", path[i]);
	return puts(""), flush, read();
}

bool one_edge(int a, int b){ return printf("1 %d %d\n", a, b), flush, read(); }

int main()
{
	for (int T = read(); T--; )
	{
		n = read(), memset(ans, true, sizeof ans), path.clear();
		for (int i = 0; i < n; i++) path.push_back(i);
		std::stable_sort(path.begin(), path.end(), one_edge);
		int far = n - 2;
		for (int i = n - 1; ~i; i--)
		{
			if (far == i)
			{
				for (int j = 0; j <= i; j++)
					for (int k = i + 1; k < n; k++)
						ans[path[k]][path[j]] = false;
				--far;
			}
			while (many_edge(path[i], far)) --far;
		}
		puts("3");
		for (int i = 0; i < n; i++, puts(""))
			for (int j = 0; j < n; j++)
				printf("%d", ans[i][j]);
		flush, read();
	}
	return 0;
}
