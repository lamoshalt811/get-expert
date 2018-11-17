#include <stdio.h>

long fact(int n) {
	return (n == 0) ? 1 : n * fact(n-1);
}

int ncr(int n, int r) {
	return fact(n) / ( fact(r) * fact(n - r) );
}

int main() {
	
	int n, r;
	
	scanf("%d %d", &n, &r);
	printf("%d", ncr(n,r));
	
	return 0;
}