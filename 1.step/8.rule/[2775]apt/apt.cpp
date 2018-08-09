#include <stdio.h>

int apt[15][15];

int count(int k, int n) {
	if(apt[k][n]) {
		return apt[k][n];
	} else {
		return count(k-1, n) + count(k, n-1);
	}
}

int main(){
	
	int T, K, N;
	scanf("%d", &T);
	
	for(int i=0; i<15; i++) {
		for(int j=0; j<15; j++) {
			if(i == 0) {
				apt[i][j] = j;
			} else if(i == 1) {
				apt[i][j] = j * (j+1) / 2;
			} else if(j == 1){
				apt[i][j] = 1;
			} else {
				apt[i][j] = 0;
			}
		}
	}
	
	while(T--) {
	
		scanf("%d", &K);
		scanf("%d", &N);
		
		printf("%d\n", count(K, N));
	}
	
	return 0;
}