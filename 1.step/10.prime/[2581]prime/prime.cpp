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
	
	int N1, N2;
	int i, min=-1, sum=0;
	
	scanf("%d", &N1);
	scanf("%d", &N2);
	
    setPrime();
	
	for(i=N1; i<=N2; i++) {
		if(IS_PRIME(i)) {
			sum += i;
			if(min < 0) min = i;
		}
	}
	
	if(min < 0) {
		printf("-1");
	}else {
		printf("%d\n", sum);
		printf("%d\n", min);
	}
		
	return 0;
}