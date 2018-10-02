#include <stdio.h>

static int arr[1000000];

void countSort(int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
	
	int i, j, t, max;
	int N;

	scanf("%d", &N);

	max = -1;
	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		max = (max < arr[i]) ? arr[i] : max;
	}
	 
    for (int exp = 1; max/exp > 0; exp *= 10)
        countSort(N, exp);
	
	for(i=0; i<N; i++) {
		printf("%d\n", arr[i]);
	}
	
	return 0;
	
}