#include <stdio.h>
#define MAX 10001
#define IS_PRIME(N) (arr[N] == 0)

static int arr[MAX];

void setPrime() {
	int i, j;
	
	for(i=0; i<=MAX;i++) {
		arr[i] = 0;		
	}
	
	arr[1] = 1;
	for(i=2; i<=MAX;i++) {
		if(arr[i] == 0) {
			
			for(j=i*2; j<=MAX; j+=i) {
				arr[j] = i;
			}
		}
	}
}

int main() {
	
	int T, N, i, t, cnt;
	
    setPrime();
	
	scanf("%d", &T);
	
	while(T--) {	
		scanf("%d", &N);
				
		for(i=2; i <=N/2; i++) {
			if(IS_PRIME(i) && IS_PRIME(N-i)) {
				t=i;				
			}
		}
		
		printf("%d %d\n",t, N-t);
	}
	
	return 0;
}