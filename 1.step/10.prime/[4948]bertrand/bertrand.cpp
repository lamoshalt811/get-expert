#include <stdio.h>
#define MAX 246913 //((123456*2)+1)
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
	
	int N, i, cnt;
	
    setPrime();
	
	while(1) {	
		scanf("%d", &N);
		
		if(N == 0) break;
	
		cnt=0;
		for(i=N+1; i <=2*N; i++) {
			if(IS_PRIME(i))
				cnt++;
		}
		
		printf("%d\n",cnt);
	}
	
	return 0;
}