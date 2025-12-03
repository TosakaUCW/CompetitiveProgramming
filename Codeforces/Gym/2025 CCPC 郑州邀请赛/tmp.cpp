#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

#define is_inner(x,y) (x >= 0 and x < 8 and y >= 0 and y < 8)

const int maxn = 65;

struct point {
  int x;
  int y;
};

struct point king;
struct point knights[maxn];
int kn;
int d[8][8][8][8];

int Min(int, int);
int Max(int, int);
int abs(int);

void input(){
  char a;
  char b;
  a = getchar();
  b = getchar();
  king.x = a - 'A';
  king.y = b - '1';
  kn = 0;
  while (1) {
    a = getchar();
    if (a == '\n' or a == EOF) {
      break;
    }
    b = getchar();
    knights[kn].x = a - 'A';
    knights[kn].y = b - '1';
    ++ kn;
  }

  for (int i = 0; i < 8; ++ i) {
    for (int j = 0; j < 8; ++ j) {
      for (int p = 0; p < 8; ++ p) {
        for (int q = 0; q < 8; ++ q) {
          d[i][j][p][q] = maxn * maxn;
        }
      }
      d[i][j][i][j] = 0;
    }
  }
}

struct point direct[] = {
  {-2, -1}, {-2, 1},
  {-1, -2}, {-1, 2},
  {1, 2}, {1, -2},
  {2, 1}, {2, -1}
};

inline
int abs(int x) {
  return x > 0 ? x : -x;
}

inline 
int Max(int a, int b) {
  return a > b ? a : b;
}

inline
int Min(int a, int b) {
  return a < b ? a : b; 
}

void floyd() {
  for (int i = 0; i < 64; ++ i) {
    for (int k = 0; k < 8; ++ k) {
      if (is_inner(i/8+direct[k].x, i%8+direct[k].y)) {
        d[i/8][i%8][i/8+direct[k].x][i%8+direct[k].y] = 1;
      }
    }
  }

  for (int k = 0; k < 64; ++ k) {
    for (int i = 0; i < 64; ++ i) {
      for (int j = 0; j < 64; ++ j) {
        d[i/8][i%8][j/8][j%8] = Min(d[i/8][i%8][j/8][j%8], d[i/8][i%8][k/8][k%8] + d[k/8][k%8][j/8][j%8]);
      }
    }
  }
}

void solve() {
  floyd();

  int ans = maxn * maxn;
  int sum[64];
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i < 64; ++ i) {
    for (int x = 0; x < kn; ++ x) {
      sum[i] += d[knights[x].x][knights[x].y][i/8][i%8];
    }
    //printf("%d\n", sum[i]);
  }

  int tmp;
  for (int i = 0; i < 64; ++ i) {
    for (int k = 0; k < kn; ++ k) {
      for (int j = 0; j < 64; ++ j) {
        tmp = sum[i] - d[knights[k].x][knights[k].y][i/8][i%8];
        tmp += d[knights[k].x][knights[k].y][j/8][j%8];
        tmp += d[j/8][j%8][i/8][i%8];
        tmp += Max(abs(king.x-j/8), abs(king.y-j%8));
        if (tmp < ans) {
          ans = tmp;
        }
      }
    }
  }

  printf("%d\n", ans);
}

int main () {
  input();
  solve();

  return 0;
}