#include <stdio.h>
#include <algorithm>
#include <vector>
#define NM 300005
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
using namespace std;
typedef long long int ll;
//FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
FILE *in = stdin, *out = stdout;
int n, C, m;
int a[NM], ans[10005], query[10005][2];
vector<int> cand[10005], inv[10005];
int B;
struct TREE {
	int x, cnt;
	TREE() {};
	TREE(int x, int cnt) :x(x), cnt(cnt) {};
}tree[NM * 2];
int countTree[NM * 2];
void input() {
	si(n), si(C);
	FOR(i, 1, n) si(a[i]), inv[a[i]].push_back(i);
}
TREE merge(TREE L, TREE R) {
	if (L.x == R.x && L.x != 0) {
		return TREE(L.x, L.cnt + R.cnt);
	}
	else if (L.x == R.x && L.x == 0) {
		return TREE(0, 0);
	}
	else if (L.x != R.x) {
		if (L.cnt > R.cnt) {
			return TREE(L.x, L.cnt - R.cnt);
		}
		else if (L.cnt < R.cnt) {
			return TREE(R.x, R.cnt - L.cnt);
		}
		else {
			return TREE(0, 0);
		}
	}
}
void renew(int idx, int x, int cnt) {
	tree[idx] = TREE(x, cnt);
	idx >>= 1;
	while (idx) {
		int l = idx << 1;
		int r = l + 1;
		tree[idx] = merge(tree[l], tree[r]);
		idx >>= 1;
	}
}
TREE find(int L, int R) {
	TREE res = TREE(0, 0);
	while (L <= R) {
		if (L & 1) res = merge(res, tree[L]), L++;
		if (!(R & 1)) res = merge(res, tree[R]), R--;
		L >>= 1, R >>= 1;
	}
	return res;
}
void renew2(int x, int cnt) {
	countTree[x] = cnt; x >>= 1;
	while (x) countTree[x] = countTree[x << 1] + countTree[(x << 1) + 1], x >>= 1;
}
int find2(int L, int R) {
	int res = 0;
	while (L <= R) {
		if (L & 1) res += countTree[L++];
		if (!(R & 1)) res += countTree[R--];
		L >>= 1, R >>= 1;
	}
	return res;
}
void pro() {
	si(m);
	B = n - 1;
	FOR(i, 1, n) {
		renew(B + i, a[i], 1);
	}
	FOR(i, 1, m) {
		int l, r;
		si(l), si(r);
		query[i][0] = l, query[i][1] = r;
		TREE res = find(B + l, B + r);
		if (res.x) cand[res.x].push_back(i);
	}
	FOR(i, 1, C) {
		for (auto &idx : inv[i]) renew2(B+idx, 1);

		for (auto &q : cand[i]) {
			int L = query[q][0], R = query[q][1];
			int cnt = find2(B + L, B + R);
			if (cnt > (R - L + 1) / 2) ans[q] = i;
		}

		for (auto &idx : inv[i]) renew2(B+idx, 0);
	}
	FOR(i, 1, m) {
		if (ans[i] == 0) fprintf(out, "no");
		else fprintf(out, "yes %d", ans[i]);
		if (i < m) fprintf(out, "\n");
	}
}
int main() {
	input();
	pro();
	return 0;
}