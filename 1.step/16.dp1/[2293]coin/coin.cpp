#include <stdio.h>

static int count[10001];
static int coin[100];
static int N, K;

int main() {
	
	scanf("%d %d", &N ,&K);
	
	for(register int i=0; i<N; i++) {
		scanf("%d", &coin[i]);
	}
	
	for(register int i=1; i<=K; i++) {
		
		for(register int j=0; j<N; j++) {
			
			if(coin[j] < i) {
				count[i] += count[i - coin[j]];
			} else if(coin[j] == i) {
				count[i]++;
			}
			
		}
		
	}
	
	for(register int i=0; i<=K; i++) {
		printf("%3d|", count[i]);
	}
	printf("\n");
	
	printf("%d", count[K]);
	
	return 0;
}