#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int n, m, a[1010][1010], s[1010][1010], mx[1000010], my[1000010], Mx[1000010], My[1000010], chk[1000010], ans;

int main(){
	scanf("%d", &n);
	if(n == 1){ puts("1"); return 0; }
	ans = n * n;
	fill(mx + 1, mx + ans + 1, inf);
	fill(my + 1, my + ans + 1, inf);
	fill(Mx + 1, Mx + ans + 1, -inf);
	fill(My + 1, My + ans + 1, -inf);	
	for(int i = 1; i <= n; i++){
		for(int j = 1, x; j <= n; j++){
			scanf("%d", &x);
			a[i][j] = x;
			mx[x] = min(mx[x], i);
			my[x] = min(my[x], j);
			Mx[x] = max(Mx[x], i);
			My[x] = max(My[x], j);
		}
	}
	int fl = 2;
	for(int i = 1; i <= ans; i++){
		if(mx[i] <= Mx[i]){
			fl = max(0, fl - 1);			
			s[mx[i]][my[i]]++;
			s[mx[i]][My[i] + 1]--;
			s[Mx[i] + 1][my[i]]--;
			s[Mx[i] + 1][My[i] + 1]++;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) s[j][i] += s[j - 1][i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) s[i][j] += s[i][j - 1];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!a[i][j] || chk[a[i][j]]) continue;
			if(s[i][j] > 1){
				ans--;
				chk[a[i][j]] = 1;
			}
		}
	}
	printf("%d\n", min(n * n - fl, ans));
}