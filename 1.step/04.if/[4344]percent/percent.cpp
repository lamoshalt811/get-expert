#include <stdio.h>

int main(){
	int i, C, N, arr[1001], sum, cnt;
	scanf("%d", &C);
	while(C--) {
		scanf("%d", &N);
		sum=0;
		for(i=0; i<N; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		
		
		cnt=0;
		for(i=0; i<N; i++) {
			if(arr[i] > (float)sum/N) {
				cnt++;
			}
		}
		printf("%.3f\n", (float)cnt/N*100);
	}
	return 0;
}