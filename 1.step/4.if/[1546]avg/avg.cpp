#include <stdio.h>

int arr[1001];

int main(){
	float sum = 0.0f;
	int i, N, M;
	scanf("%d", &N);

	M = 0;
	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		if(M < arr[i]) {
			M = arr[i];
		}
	}
		
	for(i=0; i<N; i++) {
		sum += 100.0f * arr[i] / M;
	}
	
	printf("%.2f\n", sum/N);
	
	return 0;
}