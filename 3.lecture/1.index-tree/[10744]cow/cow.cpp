#include <stdio.h>
#pragma warning(disable:4996)
//FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
FILE *in = stdin, *out = stdout;
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 1e9
#define NM 755
#define MOD 1000000007
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define sd(n) fscanf(in,"%lf",&n)
typedef long long int ll;

#include <stdlib.h>

struct LIST {
	ll cnt;
	LIST *l, *r;
	LIST() { cnt = 0, l = r = nullptr; }
	LIST(ll cnt) :cnt(cnt) { l = r = nullptr; }
	LIST* makeNode() {
		LIST* node = (LIST*)malloc(sizeof(LIST));
		node->cnt = 0;
		node->l = node->r = nullptr;
		return node;
	}
	LIST* getLeft() {
		if (l == nullptr) l = makeNode();
		return l;
	}
	LIST* getRight() {
		if (r == nullptr) r = makeNode();
		return r;
	}
}root[NM * NM];
int n, m, K, a[NM][NM];
ll sum[NM][NM], dy[NM][NM];
void input(){
	si(n); si(m); si(K);
	FOR(i, 1, n) FOR(j, 1, n) si(a[i][j]);
}
void Update(LIST *node, ll value, int y, int y1, int y2) {
	node->cnt = (node->cnt + value) % MOD;
	if (y1 == y2) return;
	int m = (y1 + y2) >> 1;
	if (m >= y) Update(node->getLeft(), value, y, y1, m);
	else Update(node->getRight(), value, y, m+1, y2);
}
ll Get(LIST *node, int y, int y1, int y2) {
	if (y2 <= y) return node->cnt;
	if (y1 > y) return 0;
	ll lv = 0, rv = 0;
	int m = (y1 + y2) >> 1;
	// left = (y1, m)
	if (node->l != nullptr) {
		lv = Get(node->l, y, y1, m);
	}
	// right = (m+1, y2)
	if (node->r != nullptr && m + 1 <= y) {
		rv = Get(node->r, y, m + 1, y2);
	}
	return lv + rv;
}
void pro() {
	Update(&root[a[1][1]], 1, 1, 1, m);
	sum[1][1] = dy[1][1] = 1;
	FOR(i, 1, n) sum[i][1] = 1;
	FOR(j, 1, m) sum[1][j] = 1;
	FOR(i, 2, n){
		FOR(j, 2, n) {
			ll cnt = sum[i - 1][j - 1] - Get(&root[a[i][j]], j - 1, 1, m); cnt %= MOD;
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + cnt; sum[i][j] %= MOD;
			dy[i][j] = cnt;
		}
		FOR(j, 2, n) {
			Update(&root[a[i][j]], dy[i][j], j, 1, m);
		}
	}
	fprintf(out, "%lld", (dy[n][m] + MOD) % MOD);
}
int main() {
	input();
	pro();
	return 0;
}
