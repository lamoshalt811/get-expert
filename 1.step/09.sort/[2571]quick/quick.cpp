#include <stdio.h>

static int arr[1000000];


void Swap(int *arr,int first,int second) {
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}
  
void quickSort(int left, int right) 
{ 
    if (left >= right) 
		return;
     
	int pivot = arr[right];
	int l = left;
	int r = right-1;

	while(l <= r) {    // 교차하기 전까지 진행
		while(l<=r && arr[l]<=pivot) l++;
		while(l<=r && arr[r]>=pivot) r--;
		if(l<r) Swap(arr,l,r);
	}
	Swap(arr,l,right);

	quickSort(left, l - 1); 
	quickSort(l + 1, right); 
} 

int main() {
	
	int i, j, t;
	int N;

	scanf("%d", &N);

	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}

	quickSort(0, N-1);
	
	for(i=0; i<N; i++) {
		printf("%d\n", arr[i]);
	}
	
	return 0;
	
}