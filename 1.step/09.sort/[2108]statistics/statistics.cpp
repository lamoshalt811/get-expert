#include <stdio.h>

static int arr[500001];
static int cnt[8001];

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
	
	int i, j, N, n, t, sum, max, min;
	
	sum=0;
	for(i=0; i<8001; i++) {
		cnt[i] = 0;
	}
	
	scanf("%d", &N);	
	
	for(i=0; i<N; i++) {
		
		scanf("%d", &n);
		
		arr[i] = n;
		cnt[n+4000]++;
		sum += n;
		
		if(i == 0) {
			max = n;
			min = n;			
		} else {
			max = (max > n) ? max : n;
			min = (min < n) ? min : n;
		}
	}
	
	for(i = (N-1)/2; i >= 0; i--) {
		downheap(i,N);
	}
	
	for(i = N-1; i > 0; i--) {
		t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;
		
		downheap(0, i);
	}
	
	int maxCnt=0, maxCntN1=0, maxCntN2=-1;
	
	for(i=0; i<=8000; i++) {
		if(cnt[i] > maxCnt) {
			maxCnt = cnt[i];
			maxCntN1 = i;
			maxCntN2 = -1;
		} else if(cnt[i] == maxCnt && maxCntN2 == -1) {
			maxCntN2 = i;
		}
	}
		
	printf("%d\n", (int) ((double)sum/N + ((sum > 0) ? 0.5d : -0.5d)));
	printf("%d\n", arr[N/2]);
	printf("%d\n", (maxCntN2 > 0) ? maxCntN2 - 4000 : maxCntN1 - 4000 );
	printf("%d\n",max - min);
}