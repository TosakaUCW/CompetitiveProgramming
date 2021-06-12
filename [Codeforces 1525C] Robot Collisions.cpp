#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 3e5 + 5;

int n, nn, m;
int top, ans[N];
struct Node 
{
	int pos, L, idx; 
	bool friend operator < (Node a, Node b) { return a.pos < b.pos; }
} a[N], b[N], st[N];

void solve()
{
	std::sort(a + 1, a + 1 + n), top = 0;
	for (int i = 1; i <= n; i++) 
		if (a[i].L)
		{
			if (!top)
				a[i].pos = -a[i].pos, a[i].L = 0, st[++top] = a[i];
			else
				ans[a[i].idx] = ans[st[top].idx] = a[i].pos - st[top].pos >> 1, top--;
		}
		else
			st[++top] = a[i];
	if (top <= 1) return;
	if (top & 1) { for (int i = 1; i < top; i++) st[i] = st[i + 1]; --top; }
	for (int i = 2; i <= top; i += 2)
		st[i].pos = 2 * m - st[i].pos;
	for (int i = 1; i <= top; i+= 2)
		ans[st[i].idx] = ans[st[i + 1].idx] = st[i + 1].pos - st[i].pos >> 1;
}

void pre()
{
    memset(ans, -1, sizeof ans);
    scanf("%d%d", &nn, &m);
	for (int i = 1; i <= nn; i++) b[i].idx = i, scanf("%d", &b[i].pos);
	for (int i = 1; i <= nn; i++) { char ch; scanf("%s", &ch); a[i].L = ch == 'L'; }
	n = 0;
	for (int i = 1; i <= nn; i++) if (b[i].pos % 2 == 0) a[++n] = b[i];
	solve();
	n = 0;
	for (int i = 1; i <= nn; i++) if (b[i].pos % 2 == 1) a[++n] = b[i];
	solve();
}

void print()
{
	for (int i = 1; i <= nn; i++) printf("%d ", ans[i]);
	puts("");
}

int main()
{
    int T;
	for (scanf("%d", &T); T--; pre(), solve(), print());
	return 0;
}
