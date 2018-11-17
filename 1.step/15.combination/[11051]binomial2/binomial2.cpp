#include <stdio.h>

static int _NCR[1001][1001];

int main() {
	
	int n, r;

	scanf("%d %d", &n, &r);
		
	_NCR[1][0] = 1;
	_NCR[1][1] = 1;
	
	for (int i=2; i<=n; i++) {
		for (int j=0; j<=i; j++) {			
			_NCR[i][j] = (i == j || j == 0) ? 1 : _NCR[i-1][j-1] + _NCR[i-1][j];
			_NCR[i][j] %= 10007;
		}
	}
		
	printf("%d", _NCR[n][r]);
	
	return 0;
}