#include <stdio.h>

static int DP_STEP1[305];
static int DP_STEP2[305];

int main() {
	
	int N, n;
	scanf("%d", &N);
	
	for(register int i=2; i<=N+1; i++) {
		scanf("%d", &n);
		DP_STEP1[i] = n + DP_STEP2[i-1];
		DP_STEP2[i] = n + ((DP_STEP1[i-2] > DP_STEP2[i-2]) ? DP_STEP1[i-2] : DP_STEP2[i-2]);
	}
	
	printf("===========\n");
	for(register int i=2; i<=N+1; i++) {
		printf("%3d|", DP_STEP1[i]);
	}
	printf("\n");	
	for(register int i=2; i<=N+1; i++) {
		printf("%3d|", DP_STEP2[i]);
	}
	printf("\n");
	printf("===========\n");
	
	printf("%d", (DP_STEP1[N+1] > DP_STEP2[N+1]) ? DP_STEP1[N+1] : DP_STEP2[N+1]);
	
	return 0;
}