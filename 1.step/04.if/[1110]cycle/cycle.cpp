#include <stdio.h>

int main() {
	
	int N, M, cnt;
	
	scanf("%d", &N);
	
	cnt=1;
	M = (N%10)*10 + ((N/10) + (N%10))%10;
	
	while(N!=M) {		
		cnt++;	
		M = (M%10)*10 + ((M/10) + (M%10))%10;
	}
	
	printf("%d\n", cnt);
		
	return 0;
}