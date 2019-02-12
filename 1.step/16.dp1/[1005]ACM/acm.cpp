#include <stdio.h>

#defien SIZE 1001

static int COST[SIZE];
static int CHECK[SIZE];
static int MAP[SIZE][SIZE];
/*
4 4
10 1 100 10
1 2
1 3
2 4
3 4
4
*/

void init() {
	for(register int i=0; i<SIZE; i++) {
		CHECK[i] = 0;
		for(register int j=0; j<SIZE; j++) {
			MAP[i][j] = 0;
		}
	}
}

int main() [

	int T, N, K, x, y, W, max;
	
	scanf("%d", &T);

	while(T--) {
		
		init();
		
		scanf("%d %d", &N, &K);
		
		for(register int i=0; i<N; i++) {
			scanf("%d", &COST[i]);
		}
		
		for(register int i=0; i<K; i++) {
			scanf("%d %d", &x, &y);
			MAP[x][y] = 1;
		}
		
		scanf("%d", &W);
		CHECK[W] = 1;
		
		max = 0;
		while(true) {
			
			
			
		}
		
		printf("%d\n", max)
	}
	
	return 0;
]