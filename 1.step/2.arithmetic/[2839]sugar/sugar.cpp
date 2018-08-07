	#include <stdio.h>

	int arr[5001];

	int main() {

		int i, N;

		scanf("%d", &N);

		arr[1] = -1;
		arr[2] = -1;
		arr[3] = 1;
		arr[4] = -1;
		arr[5] = 1;
		for(i=6; i<=N; i++) {
			if(arr[i-3] > 0 && arr[i-5] > 0) {
				arr[i] = 1 + ((arr[i-3] < arr[i-5]) ? arr[i-3] : arr[i-5]);
			} else if(arr[i-3] > 0) {
				arr[i] = 1 + arr[i-3];
			} else if(arr[i-5] > 0) {
				arr[i] = 1 + arr[i-5];
			} else {
				arr[i] = -1;
			}		
		}

		printf("%d\n", arr[N]);

		return 0;
	}