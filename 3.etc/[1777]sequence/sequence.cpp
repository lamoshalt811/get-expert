#include <stdio.h>
// 1988ms

int arr[100001];

void insert(int index, int num) {
	
	// shfit	
	for(int i=num; i>index; i--) {
		arr[i] = arr[i-1];	
	}
	
	// set
	arr[index] = num;
}
	

int main(){
	
	int i, N, is;
	
	scanf("%d", &N);
	for(i=1; i<=N;i++) {
		scanf("%d", &is);
		
		insert(i-is, i);
	}
	
	for(i=1; i<=N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}