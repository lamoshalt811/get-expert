#include <stdio.h>

long long int gcd(long long int a, long long int b){
	while(b!=0){
		long long int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int main(){
	
	long long int n1, n2, n3, g;
		
	scanf("%lld %lld", &n1, &n2);

	if (n2 > n1) {
		n3 = n1;
		n1 = n2;
		n2 = n3;
	}
	
	g = gcd(n1, n2);
	
	for(long long int i=0; i<g; i++) {
		printf("1");
	}
	printf("\n");
	
	return 0;
}