#include <stdio.h>

static int QUEUE[50];
static int NEXT[50];
static int PREV[50];
static int N, M, SIZE;

int pop(int p) {
	
	if(SIZE == 0)
		return -1;
	
	PREV[ NEXT[p] ] = PREV[p];
	NEXT[ PREV[p] ] = NEXT[p];
	
	--SIZE;
	return NEXT[p];
}

int main(){
	
	int i, j, t;
	int pos, out, cnt, weight;
	
	scanf("%d %d", &N, &M);
	
	SIZE = N;
	for(i=0; i<N; i++) {
		QUEUE[i] = i+1;
		PREV[i] = (i == 0) ? N-1 : i-1;
		NEXT[i] = (i + 1 ) % N;
	}
	
	pos = 0;
	cnt = 0;
	for(i=0; i<M; i++) {
		scanf("%d", &out);
		t=0;
		weight = QUEUE[pos] < out ? 1 : -1;
		
		while(true) {
			
			if(QUEUE[pos] == out) {
				
				cnt += (t > SIZE/2) ? SIZE-t : t;
				pos = pop(pos);
				
				break;
			}
			
			++t;
			pos = (weight) ? NEXT[pos] : PREV[pos];
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}