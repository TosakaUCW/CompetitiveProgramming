#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e3 + 5;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

int n, m;
ll ans;
int f[N][N][4], g[N][N], b[N];
bool a[N][N];

void calc(int x, int y1, int y2)
{
	for (int y = y1; y <= y2; y++) b[y] = g[x][y];
	std::sort(b + y1, b + 1 + y2), b[y1 - 1] = 1;
	for (int y = y1; y <= y2; y++)
		ans += 1LL * (b[y] - b[y - 1]) * (y2 - y + 1) * (y2 - y) / 2;
}

signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read() ^ 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j])
				for (int k = 0; k < 2; k++)
					f[i][j][k] = 1 + f[i + dx[k]][j + dy[k]][k];
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			if (a[i][j])
				for (int k = 2; k < 4; k++)
					f[i][j][k] = 1 + f[i + dx[k]][j + dy[k]][k];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            g[i][j] = std::min(f[i][j][1], f[i][j][3]);
            for (int k = 0; k < 4; k++)
                if (f[i][j][k])
                    f[i][j][k]--;
        }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j]) 
				calc(i, j, j + f[i][j][2]), j += f[i][j][2];
	return printf("%lld", ans), 0;
}
