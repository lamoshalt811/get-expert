#include <stdio.h>

static int DP_R[1001];
static int DP_G[1001];
static int DP_B[1001];

int main(){
	
	int N;
	int r, g, b, pos=0;
	
	scanf("%d", &N);
	
	while(N--) {
		
		scanf("%d %d %d", &r, &g, &b);
		
		DP_R[pos] = r;
		DP_G[pos] = g;
		DP_B[pos] = b;
		
		if(pos > 0) {
			DP_R[pos] += ((DP_G[pos-1] > DP_B[pos-1]) ? DP_B[pos-1] : DP_G[pos-1]);
			DP_G[pos] += ((DP_R[pos-1] > DP_B[pos-1]) ? DP_B[pos-1] : DP_R[pos-1]);
			DP_B[pos] += ((DP_G[pos-1] > DP_R[pos-1]) ? DP_R[pos-1] : DP_G[pos-1]);
		}
		
		pos++;
	}
	
	if(DP_R[pos-1] > DP_G[pos-1]) {
		if(DP_G[pos-1] > DP_B[pos-1]) 
			printf("%d", DP_B[pos-1]);
		else
			printf("%d", DP_G[pos-1]);
	} else {
		if(DP_R[pos-1] > DP_B[pos-1]) 
			printf("%d", DP_B[pos-1]);
		else
			printf("%d", DP_R[pos-1]);
		
	}
	
	return 0;
}