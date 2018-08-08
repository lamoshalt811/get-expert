#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 755, dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};
int n, m, a[N][N], l[N][N];
ll s[4][N][N], ts[N][N], ans;

void calc(int ix, int fx, int iy, int fy, int d){
	for(int i = ix; i != fx; i += dx[d]){
		int cs = 0;
		stack<int> st;
		st.push(iy - dy[d]);
		for(int j = iy; j != fy; j += dy[d]){
			l[i][j] = a[i][j] * (l[i - dx[d]][j] + 1);
			while(!st.empty()){
				if(l[i][st.top()] < l[i][j]) break;
				int tx = st.top(), tv = l[i][st.top()];
				st.pop();
				if(!st.empty()) cs -= abs(tx - st.top()) * tv;
			}
			if(!st.empty()) cs += abs(j - st.top()) * l[i][j];
			st.push(j);
			s[d][i][j] = cs;
		}
	}
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
        s[d][i][j] += s[d][i - 1][j] + s[d][i][j - 1] - s[d][i - 1][j - 1];
}

ll get(int x, int a, int b, int c, int d){
    return s[x][c][d] - s[x][c][b - 1] - s[x][a - 1][d] + s[x][a - 1][b - 1];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%1d", a[i] + j);
	calc(1, n + 1, 1, m + 1, 0);
    calc(1, n + 1, m, 0, 1);
    calc(n, 0, 1, m + 1, 2);
    calc(n, 0, m, 0, 3);
    ans = 1LL << 62;
    for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans = min(ans,
                get(0, 1, j, i - 1, m) + get(1, i, j + 1, n, m) +
                get(3, i + 1, 1, n, j) + get(2, 1, 1, i, j - 1));
		}
	}
	printf("%lld\n", ans);
}