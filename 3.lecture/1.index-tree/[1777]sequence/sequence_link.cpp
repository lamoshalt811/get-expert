#include <stdio.h>
#pragma warning(disable:4996)
//FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
FILE *in = stdin, *out = stdout;
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 0x7fffffff
#define NM 100005
#define MOD 1000000007
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define sd(n) fscanf(in,"%lld",&n)
typedef long long int ll;

int n, K, tree[NM * 4], B, a[NM], ans[NM];
void input() {
	si(n);
	FOR(i, 1, n) si(a[i]);
	B = 1;
	while (B < n) B <<= 1;
	B--;
}
void Update(int idx, int cnt) {
	idx += B; tree[idx] += cnt; idx >>= 1;
	while (idx) tree[idx] = tree[idx << 1] + tree[(idx << 1) + 1], idx >>= 1;
}
int Find(int X) {
	int idx = 1;
	while (idx <= B) {
		idx <<= 1;
		if (tree[idx] < X) {
			X -= tree[idx];
			idx++;
		}
	}
	return idx - B;
}
void pro() {
	FOR(i, 1, n) Update(i, 1);
	for (int i = n; i >= 1; i--) {
		int idx = Find(i - a[i]);
		ans[idx] = i;
		Update(idx, -1);
	}
	FOR(i, 1, n) fprintf(out, "%d ", ans[i]);
}
int main() {
	input();
	pro();
	return 0;
}