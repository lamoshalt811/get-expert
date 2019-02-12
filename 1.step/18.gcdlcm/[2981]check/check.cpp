#include <stdio.h>

static int arr[101];

int main() {
	
	int i, j, N, max=0, m;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		if(max < arr[i])
			max = arr[i];
	}
	
	for(i=2; i<max; i++) {
		
		m = arr[0] % i;
		
		for(j=1; j<N; j++) {
			
			if(m != arr[j]%i)
				break;
		}
		
		if(j == N)
			printf("%d ", i);
	}
	
	return 0;
}