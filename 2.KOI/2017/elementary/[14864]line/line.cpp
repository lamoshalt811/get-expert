#include <stdio.h>

int N, M;
int arr[100001];
int out[100001];
int in[100001];
int check[100001];

int main(void) {
	int i=0;
	int X, Y;
	
	scanf("%d %d", &N, &M);
	
	for(i=1; i<=N; i++) {
		arr[i] = 0;
		out[i] = 0;
		in[i] = 0;
		check[i] = 0;
	}
		
	for(i=0; i<M; i++) {
		scanf("%d %d", &X, &Y);
		
		out[X]++;
		in[Y]++;
	}
	
	for(i=1; i<=N; i++) {
			
		if(out[i] == 0) {
			arr[i] = i - in[i];
		} else {
			arr[i] = i + out[i] - in[i];
		}
			
		if(check[arr[i]] == 0) {
			check[arr[i]] = 1;
		} else {
			printf("-1");
			return 0;
		}
	}
		
	printf("%d", arr[1]);
	for(i=2; i<=N; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
    return 0;
}


