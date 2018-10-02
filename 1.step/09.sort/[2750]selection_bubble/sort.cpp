#include <stdio.h>

static int arr[1001];

int main(){
	
	int N, i, j, t;
	
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	
	// for(i=0; i<N-1; i++) {
	// 	for(j=i+1; j<N; j++) {
	// 		if(arr[i] > arr[j]) {
	// 			t = arr[i];
	// 			arr[i] = arr[j];
	// 			arr[j] = t;
	// 		}
	// 	}
	// }
	
	for(i=1; i<N; i++) {
		for(j=0; j<N-i; j++) {
			if(arr[j] > arr[j+1]) {
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}


	for(i=0; i<N; i++) {
		printf("%d\n", arr[i]);
	}
	
	return 0;
}