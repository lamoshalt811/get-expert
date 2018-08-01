#include <stdio.h>

int N, M;
int arr[100001];
int check[100001];

int main(void) {
	int i=0;
	int X, Y;
	
	scanf("%d %d", &N, &M);
	
	for(i=1; i<=N; i++) {
		arr[i] = i;
		check[i] = 0;
	}
		
	for(i=0; i<M; i++) {
		scanf("%d %d", &X, &Y);
		arr[X]++;
		arr[Y]--;
	}
	
	for(i=1; i<=N; i++) {
		if(check[arr[i]] > 0) {
			printf("-1");
			return 0;
		}
		check[arr[i]] = 1;
	}
		
	printf("%d", arr[1]);
	for(i=2; i<=N; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
    return 0;
}


