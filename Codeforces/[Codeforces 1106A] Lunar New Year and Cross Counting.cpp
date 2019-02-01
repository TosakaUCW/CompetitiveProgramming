#include <stdio.h>
#include <iostream>

const int N = 500 + 5;

int n, ans;
int m[N][N];

int main()
{
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		char ch;
		for (int j = 1; j <= n; j++)
		{
			std::cin >> ch;
			m[i][j] = ch == '.' ? 1 : 0;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i + 1 <= n and j + 1 <= n and i - 1 >= 1 and j - 1 >= 1)
				if (m[i][j] + m[i - 1][j - 1] + m[i - 1][j + 1] + m[i + 1][j - 1] + m[i + 1][j + 1] == 0)
					ans++;
	printf("%d", ans);
	return 0;
}