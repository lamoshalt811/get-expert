#include <stdio.h>

static int CALL_0[41];
static int CALL_1[41];

int main () {
	
	int i;
	int T, N;
	
	CALL_0[0] = 1;
	CALL_1[0] = 0;
	
	CALL_0[1] = 0;
	CALL_1[1] = 1;
	
	for(i=2; i<=40; i++) {
		CALL_0[i] = CALL_0[i-1] + CALL_0[i-2];
		CALL_1[i] = CALL_1[i-1] + CALL_1[i-2];
	}
	
	scanf("%d", &T);
	
	while(T--) {
		
		scanf("%d", &N);
		
		printf("%d %d\n", CALL_0[N], CALL_1[N]);
	}
	
	return 0;
}