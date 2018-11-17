#include <stdio.h>

int main() {
	
	long long int N=1;
	int n;
	
	scanf("%d", &n);
	
	while(n) {
		N *= n;
		n--;
	} 
	
	printf("%lld", N);
	return 0;
}