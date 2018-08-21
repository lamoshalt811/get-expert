#include <stdio.h>

static int arr[1000000];

// void downheap(int cur, int k)
// {
// 	int left, right, p, t;
	
// 	while(cur < k) {
		
// 		left = cur * 2 + 1;
// 		right = cur * 2 + 2;

// 		if (left >= k && right >= k) 
// 			break;

// 		p = cur;
// 		if (left < k && arr[p] < arr[left]) {
// 			p = left;
// 		}
// 		if (right < k && arr[p] < arr[right]) {
// 			p = right;
// 		}
// 		if (p == cur) break;

// 		t = arr[cur];
// 		arr[cur] = arr[p];
// 		arr[p] = t;
		
// 		cur=p;
// 	}
// }

void downheap(int cur, int N)
{
	int left, right, p, t;
			
	left = cur * 2 + 1;
	right = cur * 2 + 2;

	if (left >= N && right >= N) 
		return;

	p = cur;
	if (left < N && arr[p] < arr[left]) {
		p = left;
	}
	if (right < N && arr[p] < arr[right]) {
		p = right;
	}
	
	if (p == cur) 
		return;

	t = arr[cur];
	arr[cur] = arr[p];
	arr[p] = t;

	downheap(p, N);	
}

int main() {
	
	int i, j, t;
	int N;

	scanf("%d", &N);

	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}

	// heapify
	for(i = (N-1)/2; i >= 0; i--) {
		downheap(i,N);
	}
	
	for(i = N-1; i > 0; i--) {
		t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;
		
		downheap(0, i);
	}
	
	for(i=0; i<N; i++) {
		printf("%d\n", arr[i]);
	}
	
	return 0;
	
}