#include <stdio.h>

static int * count[10000];
static int N, K;

int main() {
	
	int n;
	scanf("%d %d", &N ,&K);
	
	for(register int i=0; i<K; i++) {
		count[i] = new int[ (i < 100) ? i+1 : 100 ];
	}
		
	for(register int i=0; i<N; i++) {
		scanf("%d", &n);
				
		// count[0][0] = 1;
		
	}
	
	printf("==");
	
	// DP
	for(register int i=0; i<K; i++) {
		
		for(register int j=0; j<100; j++) {
			
			if( count[j][j] == 1 && i > j) {
				printf("%d %d\n", i, j);
				for(register int k = j; k< (i < 100) ? i+1 : 100 ; k++) {
					count[i][j] += count[i - j - 1][k];	
				}
				
			}
			
		}
		
	}
		
	for(register int i=0; i<5; i++) {
		
		for(register int j=0; j<K; j++) {
		
			printf("%3d|", count[j][i]);
		}
		printf("\n");	
	}
	
	int sum=0;
	for(register int i=0; i<K; i++) {
		sum += count[K+1][i];
	}
	printf("%d", sum);
		
	
	return 0;
}