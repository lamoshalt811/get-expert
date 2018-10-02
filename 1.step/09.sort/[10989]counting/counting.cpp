#include <stdio.h>
#include <stdlib.h>

static int arr[10000000];
static int result[10000000];

int main(){

	int count[10001];	
	int N, i, j, t, max;
	
	max = 0;
	for(i=0; i<=10001; i++) {
		count[i] = 0;
	}
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		count[ arr[i] ]++;
		
		if(max < arr[i]) {
			max = arr[i];
		}
	}
		
	for(i=0; i<max; i++) {
		count[i+1] += count[i];
	}
	
	for(i=0; i<N; i++) {
		result[ count[ arr[i] ]-1 ] = arr[i];
		count[ arr[i] ]--;
	}
		
	for(i=0; i<N; i++) {
		printf("%d\n", result[i]);
	}
		
	return 0;
}