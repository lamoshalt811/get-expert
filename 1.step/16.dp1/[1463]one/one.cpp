#include <stdio.h>

static int cnt[1000001];

int main(){
	
	int N;
	scanf("%d", &N);
	
	for(register int i=2; i<=N; i++) {
		
		// +1
		cnt[i] = cnt[i-1] + 1;
		
		// *2
		if( i % 2 == 0 && cnt[i] > (cnt[i/2] +1) ) {
			cnt[i] = cnt[i/2] + 1;
		}
		
		// *3
		if( i % 3 == 0 && cnt[i] > (cnt[i/3] +1) ) {
			cnt[i] = cnt[i/3] + 1;
		}
		
	}
	
	printf("%d", cnt[N]);
	
	return 0;
}