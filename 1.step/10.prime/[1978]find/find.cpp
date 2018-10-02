#include <stdio.h
#define MAX 1001
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
	
	int N;
	int i, n, cnt=0;
	scanf("%d", &N);
	
    setPrime();
	
	for(i=0; i<N; i++) {
		scanf("%d", &n);
		if(IS_PRIME(n))
			cnt++;
	}
	
	printf("%d", cnt);
	
	return 0;
}