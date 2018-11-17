#include <stdio.h>

static int TRI[501][501];

int main() {
	
	int max, N, n;
	
	scanf("%d", &N);
	
	for(register int i=1; i<=N; i++) {
		for(register int j=1; j<=i; j++) {
			scanf("%d", &n);			
			TRI[i][j] = n + ( TRI[i-1][j-1] > TRI[i-1][j] ? TRI[i-1][j-1] : TRI[i-1][j] );
		}
	}
	
	max = -1;
	for(register int i=1; i<=N; i++) {
		if(max < TRI[N][i]) {
			max = TRI[N][i];
		}
	}
	printf("%d", max);
	
	return 0;
}